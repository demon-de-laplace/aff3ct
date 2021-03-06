#include <chrono>
#include <sstream>
#include <algorithm>

#include "Tools/Exception/exception.hpp"

#include "Decoder_repetition.hpp"

using namespace aff3ct::module;
using namespace aff3ct::tools;

template <typename B, typename R>
Decoder_repetition<B,R>
::Decoder_repetition(const int& K, const int& N, const bool buffered_encoding, const int n_frames,
                     const std::string name)
: Decoder_SISO<B,R>(K, N, n_frames, 1, name),
  rep_count((N/K) -1), buffered_encoding(buffered_encoding), sys(K), par(K * rep_count), ext(K)
{
	if (N % K)
	{
		std::stringstream message;
		message << "'K' has to be a multiple of 'N' ('K' = " << K << ", 'N' = " << N << ").";
		throw invalid_argument(__FILE__, __LINE__, __func__, message.str());
	}
}

template <typename B, typename R>
Decoder_repetition<B,R>
::~Decoder_repetition()
{
}

template <typename B, typename R>
void Decoder_repetition<B,R>
::_load(const R *Y_N)
{
	if (!buffered_encoding)
	{
		for (auto i = 0; i < this->K; i++)
		{
			const auto off1 = i * (rep_count +1);
			const auto off2 = off1 +1;

			sys[i] = Y_N[off1];
			for (auto j = 0; j < rep_count; j++)
				par[j*this->K +i] = Y_N[off2 +j];
		}
	}
	else
	{
		std::copy(Y_N, Y_N + this->K, sys.begin());
		for (auto i = 0; i < rep_count; i++)
			std::copy(Y_N + (i +1) * this->K, Y_N + (i +2) * this->K, par.begin() + (i +0) * this->K);
	}
}

template <typename B, typename R>
void Decoder_repetition<B,R>
::_hard_decode(const R *Y_N, B *V_K, const int frame_id)
{
	auto t_load = std::chrono::steady_clock::now(); // ----------------------------------------------------------- LOAD
	_load(Y_N);
	auto d_load = std::chrono::steady_clock::now() - t_load;

	auto t_decod = std::chrono::steady_clock::now(); // -------------------------------------------------------- DECODE
	this->_soft_decode(sys.data(), par.data(), ext.data(), frame_id);
	auto d_decod = std::chrono::steady_clock::now() - t_decod;

	auto t_store = std::chrono::steady_clock::now(); // --------------------------------------------------------- STORE
	// take the hard decision
	auto vec_loop_size = (this->K / mipp::nElReg<R>()) * mipp::nElReg<R>();
	for (auto i = 0; i < vec_loop_size; i += mipp::nElReg<R>())
	{
		const auto r_ext = mipp::Reg<R>(&ext[i]);
		const auto r_s = mipp::cast<R,B>(r_ext) >> (sizeof(B) * 8 - 1);

		r_s.store(&V_K[i]);
	}
	for (auto i = vec_loop_size; i < this->K; i++)
		V_K[i] = ext[i] < 0;
	auto d_store = std::chrono::steady_clock::now() - t_store;

	this->d_load_total  += d_load;
	this->d_decod_total += d_decod;
	this->d_store_total += d_store;
}

// ==================================================================================== explicit template instantiation
#include "Tools/types.h"
#ifdef MULTI_PREC
template class aff3ct::module::Decoder_repetition<B_8,Q_8>;
template class aff3ct::module::Decoder_repetition<B_16,Q_16>;
template class aff3ct::module::Decoder_repetition<B_32,Q_32>;
template class aff3ct::module::Decoder_repetition<B_64,Q_64>;
#else
template class aff3ct::module::Decoder_repetition<B,Q>;
#endif
// ==================================================================================== explicit template instantiation
