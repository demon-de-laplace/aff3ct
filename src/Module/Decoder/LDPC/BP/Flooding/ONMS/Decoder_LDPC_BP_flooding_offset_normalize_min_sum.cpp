#include <limits>
#include <sstream>

#include "Tools/Exception/exception.hpp"
#include "Tools/Math/utils.h"

#include "Decoder_LDPC_BP_flooding_offset_normalize_min_sum.hpp"

using namespace aff3ct::module;
using namespace aff3ct::tools;

template <typename R>
inline R normalize(const R val, const float factor)
{
	     if (factor == 0.125f) return div8<R>(val);
	else if (factor == 0.250f) return div4<R>(val);
	else if (factor == 0.375f) return div4<R>(val) + div8<R>(val);
	else if (factor == 0.500f) return div2<R>(val);
	else if (factor == 0.625f) return div2<R>(val) + div8<R>(val);
	else if (factor == 0.750f) return div2<R>(val) + div4<R>(val);
	else if (factor == 0.875f) return div2<R>(val) + div4<R>(val) + div8<R>(val);
	else if (factor == 1.000f) return val;
	else
	{
		std::stringstream message;
		message << "'factor' can only be 0.125f, 0.250f, 0.375f, 0.500f, 0.625f, 0.750f, 0.875f or 1.000f ('factor' = "
		        << factor << ").";
		throw invalid_argument(__FILE__, __LINE__, __func__, message.str());
	}
}

template <>
inline float normalize(const float val, const float factor)
{
	return val * factor;
}

template <>
inline double normalize(const double val, const float factor)
{
	return val * (double)factor;
}

template <typename B, typename R>
Decoder_LDPC_BP_flooding_offset_normalize_min_sum<B,R>
::Decoder_LDPC_BP_flooding_offset_normalize_min_sum(const int &K, const int &N, const int& n_ite,
                                                    const Sparse_matrix &H,
                                                    const std::vector<unsigned> &info_bits_pos,
                                                    const float normalize_factor,
                                                    const R offset,
                                                    const bool enable_syndrome,
                                                    const int syndrome_depth,
                                                    const int n_frames,
                                                    const std::string name)
: Decoder_LDPC_BP_flooding<B,R>(K, N, n_ite, H, info_bits_pos, enable_syndrome, syndrome_depth, n_frames, name),
  normalize_factor(normalize_factor), offset(offset)
{
	if (typeid(R) == typeid(signed char))
	{
		std::stringstream message;
		message << "This decoder does not work in 8-bit fixed-point (try in 16-bit).";
		throw runtime_error(__FILE__, __LINE__, __func__, message.str());
	}
}

template <typename B, typename R>
Decoder_LDPC_BP_flooding_offset_normalize_min_sum<B,R>
::~Decoder_LDPC_BP_flooding_offset_normalize_min_sum()
{
}

// normalized offest min-sum implementation
template <typename B, typename R>
bool Decoder_LDPC_BP_flooding_offset_normalize_min_sum<B,R>
::BP_process(const R *Y_N, mipp::vector<R> &V_to_C, mipp::vector<R> &C_to_V)
{
	// beginning of the iteration upon all the matrix lines
	R *C_to_V_ptr = C_to_V.data();
	R *V_to_C_ptr = V_to_C.data();

	for (auto i = 0; i < this->n_V_nodes; i++)
	{
		// VN node accumulate all the incoming messages
		const auto length = this->n_parities_per_variable[i];

		auto sum_C_to_V = (R)0;
		for (auto j = 0; j < length; j++)
			sum_C_to_V += C_to_V_ptr[j];

		// update the intern values
		const auto temp = Y_N[i] + sum_C_to_V;

		// generate the outcoming messages to the CNs
		for (auto j = 0; j < length; j++)
			V_to_C_ptr[j] = temp - C_to_V_ptr[j];

		C_to_V_ptr += length; // jump to the next node
		V_to_C_ptr += length; // jump to the next node
	}

	auto syndrome = 0;	
	auto transpose_ptr = this->transpose.data();

	for (auto i = 0; i < this->n_C_nodes; i++)
	{
		const auto length = this->n_variables_per_parity[i];

		auto sign = 0;
		auto min1 = std::numeric_limits<R>::max();
		auto min2 = std::numeric_limits<R>::max();

		// accumulate the incoming information in CN
		for (auto j = 0; j < length; j++)
		{
			const auto value  = V_to_C[transpose_ptr[j]];
			const auto c_sign = std::signbit((float)value) ? -1 : 0;
			const auto v_abs  = (R)std::abs(value);
			const auto v_temp = min1;

			sign ^= c_sign;
			min1  = std::min(min1,          v_abs         ); // 1st min
			min2  = std::min(min2, std::max(v_abs, v_temp)); // 2nd min
		}

		auto cste1 = normalize<R>(min2 - offset, normalize_factor);
		auto cste2 = normalize<R>(min1 - offset, normalize_factor);
		cste1 = (cste1 < 0) ? 0 : cste1;
		cste2 = (cste2 < 0) ? 0 : cste2;

		// regenerate the CN outcoming values
		for (auto j = 0; j < length; j++)
		{
			const auto value   = V_to_C[transpose_ptr[j]];
			const auto v_abs   = (R)std::abs(value);
			const auto v_res   = ((v_abs == min1) ? cste1 : cste2);            // cmov
			const auto v_sig   = sign ^ (std::signbit((float)value) ? -1 : 0); // xor bit
			const auto v_to_st = (R)std::copysign(v_res, v_sig);               // magnitude of v_res, sign of v_sig

			C_to_V[transpose_ptr[j]] = v_to_st;
		}

		transpose_ptr += length;
		syndrome = syndrome || sign;
	}

	return (syndrome == 0);
}

// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template class aff3ct::module::Decoder_LDPC_BP_flooding_offset_normalize_min_sum<B_8,Q_8>;
template class aff3ct::module::Decoder_LDPC_BP_flooding_offset_normalize_min_sum<B_16,Q_16>;
template class aff3ct::module::Decoder_LDPC_BP_flooding_offset_normalize_min_sum<B_32,Q_32>;
template class aff3ct::module::Decoder_LDPC_BP_flooding_offset_normalize_min_sum<B_64,Q_64>;
#else
template class aff3ct::module::Decoder_LDPC_BP_flooding_offset_normalize_min_sum<B,Q>;
#endif
// ==================================================================================== explicit template instantiation
