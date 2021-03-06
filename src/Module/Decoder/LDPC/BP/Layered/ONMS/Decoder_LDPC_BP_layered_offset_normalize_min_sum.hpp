#ifndef DECODER_LDPC_BP_LAYERED_MIN_SUM_OFFSET_HPP_
#define DECODER_LDPC_BP_LAYERED_MIN_SUM_OFFSET_HPP_

#include "../Decoder_LDPC_BP_layered.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int, typename R = float>
class Decoder_LDPC_BP_layered_offset_normalize_min_sum : public Decoder_LDPC_BP_layered<B,R>
{
private:
	const float normalize_factor;
	const R offset;
	mipp::vector<R> contributions;

public:
	Decoder_LDPC_BP_layered_offset_normalize_min_sum(const int &K, const int &N, const int& n_ite,
	                                                 const tools::Sparse_matrix &H,
	                                                 const std::vector<unsigned> &info_bits_pos,
	                                                 const float normalize_factor = 1.f,
	                                                 const R offset = (R)0,
	                                                 const bool enable_syndrome = true,
	                                                 const int syndrome_depth = 1,
	                                                 const int n_frames = 1,
	                                                 const std::string name = "Decoder_LDPC_BP_layered_offset_normalize_min_sum");
	virtual ~Decoder_LDPC_BP_layered_offset_normalize_min_sum();

protected:
	void BP_process(mipp::vector<R> &var_nodes, mipp::vector<R> &branches);
};

template <typename B = int, typename R = float>
using Decoder_LDPC_BP_layered_ONMS = Decoder_LDPC_BP_layered_offset_normalize_min_sum<B,R>;
}
}

#endif /* DECODER_LDPC_BP_LAYERED_MIN_SUM_OFFSET_HPP_ */
