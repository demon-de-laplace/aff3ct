#include <fstream>
#include <sstream>
#include <numeric>
#include <algorithm>

#include "Tools/Exception/exception.hpp"
#include "Tools/Code/LDPC/AList/AList.hpp"

#include "Tools/Factory/LDPC/Factory_encoder_LDPC.hpp"
#include "Tools/Factory/LDPC/Factory_decoder_LDPC.hpp"

#include "Codec_LDPC.hpp"

using namespace aff3ct::module;
using namespace aff3ct::tools;

template <typename B, typename Q>
Codec_LDPC<B,Q>
::Codec_LDPC(const parameters& params)
: Codec_SISO<B,Q>(params),
  info_bits_pos(this->params.code.K),
  decoder_siso (params.simulation.n_threads, nullptr)
{
	bool is_info_bits_pos = false;
	if (!params.encoder.path.empty() && params.encoder.type == "LDPC")
	{
		std::ifstream file_G(params.encoder.path, std::ifstream::in);
		G = AList::read(file_G);

		try
		{
			info_bits_pos = AList::read_info_bits_pos(file_G, params.code.K, params.code.N);
			is_info_bits_pos = true;
		}
		catch (std::exception const&)
		{
			// information bits positions are not in the G matrix file
		}

		file_G.close();
	}

	std::ifstream file_H(params.code.alist_path, std::ifstream::in);
	H = AList::read(file_H);

	if (!is_info_bits_pos)
	{
		try
		{
			if (params.encoder.type == "LDPC_H")
			{
				auto encoder_LDPC = this->build_encoder();
				encoder_LDPC->get_info_bits_pos(info_bits_pos);
				delete encoder_LDPC;
			}
			else
				info_bits_pos = AList::read_info_bits_pos(file_H, params.code.K, params.code.N);
		}
		catch (std::exception const&)
		{
			std::iota(info_bits_pos.begin(), info_bits_pos.end(), 0);
		}
	}

	file_H.close();
}

template <typename B, typename Q>
Codec_LDPC<B,Q>
::~Codec_LDPC()
{
}

template <typename B, typename Q>
Encoder_LDPC<B>* Codec_LDPC<B,Q>
::build_encoder(const int tid, const Interleaver<int>* itl)
{
	return Factory_encoder_LDPC<B>::build(this->params.encoder.type,
	                                      this->params.code.K,
	                                      this->params.code.N_code,
	                                      G,
	                                      H,
	                                      this->params.simulation.inter_frame_level);
}

template <typename B, typename Q>
Decoder_SISO<B,Q>* Codec_LDPC<B,Q>
::_build_siso(const int tid, const Interleaver<int>* itl, CRC<B>* crc)
{
	decoder_siso[tid] = Factory_decoder_LDPC<B,Q>::build(this->params.decoder.type,
	                                                     this->params.decoder.implem,
	                                                     this->params.code.K,
	                                                     this->params.code.N_code,
	                                                     this->params.decoder.n_ite,
	                                                     H,
	                                                     info_bits_pos,
	                                                     this->params.decoder.simd_strategy,
	                                                     this->params.decoder.normalize_factor,
	                                                     (Q)this->params.decoder.offset,
	                                                     this->params.decoder.enable_syndrome,
	                                                     this->params.decoder.syndrome_depth,
	                                                     this->params.simulation.inter_frame_level);
	return decoder_siso[tid];
}

template <typename B, typename Q>
SISO<Q>* Codec_LDPC<B, Q>
::build_siso(const int tid, const Interleaver<int>* itl, CRC<B>* crc)
{
	return this->_build_siso(tid, itl, crc);
}

template <typename B, typename Q>
Decoder<B,Q>* Codec_LDPC<B,Q>
::build_decoder(const int tid, const Interleaver<int>* itl, CRC<B>* crc)
{
	if (decoder_siso[tid] != nullptr)
	{
		auto ptr = decoder_siso[tid];
		decoder_siso[tid] = nullptr;
		return ptr;
	}
	else
	{
		auto decoder = this->_build_siso(tid, itl, crc);
		decoder_siso[tid] = nullptr;
		return decoder;
	}
}

template <typename B, typename Q>
void Codec_LDPC<B,Q>
::extract_sys_par(const mipp::vector<Q> &Y_N, mipp::vector<Q> &sys, mipp::vector<Q> &par)
{
	const auto K = this->params.code.K;
	const auto N = this->params.code.N_code;

	if ((int)Y_N.size() != N * this->params.simulation.inter_frame_level)
	{
		std::stringstream message;
		message << "'Y_N.size()' has to be equal to 'N' * 'inter_frame_level' ('Y_N.size()' = " << Y_N.size()
		        << ", 'N' = " << N << ", 'inter_frame_level' = " << this->params.simulation.inter_frame_level << ").";
		throw length_error(__FILE__, __LINE__, __func__, message.str());
	}

	if ((int)sys.size() != K * this->params.simulation.inter_frame_level)
	{
		std::stringstream message;
		message << "'sys.size()' has to be equal to 'K' * 'inter_frame_level' ('sys.size()' = " << sys.size()
		        << ", 'K' = " << K << ", 'inter_frame_level' = " << this->params.simulation.inter_frame_level << ").";
		throw length_error(__FILE__, __LINE__, __func__, message.str());
	}

	if ((int)par.size() != (N - K) * this->params.simulation.inter_frame_level)
	{
		std::stringstream message;
		message << "'par.size()' has to be equal to ('N' - 'K') * 'inter_frame_level' ('par.size()' = " << par.size()
		        << ", 'N' = " << N << ", 'K' = " << K << ", 'inter_frame_level' = "
		        << this->params.simulation.inter_frame_level << ").";
		throw length_error(__FILE__, __LINE__, __func__, message.str());
	}

	// extract systematic and parity information
	auto sys_idx = 0;
	for (auto f = 0; f < this->params.simulation.inter_frame_level; f++)
	{
		for (auto i = 0; i < K; i++)
			sys[f * K +i] = Y_N[f * N + info_bits_pos[i]];

		for (auto i = 0; i < N; i++)
			if (std::find(info_bits_pos.begin(), info_bits_pos.end(), i) != info_bits_pos.end())
			{
				par[sys_idx] = Y_N[f * N +i];
				sys_idx++;
			}
	}
}

// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template class aff3ct::tools::Codec_LDPC<B_8,Q_8>;
template class aff3ct::tools::Codec_LDPC<B_16,Q_16>;
template class aff3ct::tools::Codec_LDPC<B_32,Q_32>;
template class aff3ct::tools::Codec_LDPC<B_64,Q_64>;
#else
template class aff3ct::tools::Codec_LDPC<B,Q>;
#endif
// ==================================================================================== explicit template instantiation
