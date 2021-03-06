#ifndef DECODER_POLAR_SC_FAST_SYS_
#define DECODER_POLAR_SC_FAST_SYS_

#include <map>
#include <vector>
#include <mipp.h>

#include "Tools/Code/Polar/Pattern_polar_parser.hpp"
#include "Tools/Code/Polar/API/API_polar_dynamic_seq.hpp"
#include "Tools/Code/Polar/decoder_polar_functions.h"

#include "../../Decoder.hpp"

namespace aff3ct
{
namespace module
{
template <typename B, typename R, class API_polar>
class Decoder_polar_ASCL_fast_CA_sys;

template <typename B, typename R, class API_polar>
class Decoder_polar_ASCL_MEM_fast_CA_sys;

template <typename B = int, typename R = float,
          class API_polar = tools::API_polar_dynamic_seq<B, R, tools::f_LLR <  R>,
                                                               tools::g_LLR <B,R>,
                                                               tools::g0_LLR<  R>,
                                                               tools::h_LLR <B,R>,
                                                               tools::xo_STD<B  >>>
class Decoder_polar_SC_fast_sys : public Decoder<B,R>
{
	friend Decoder_polar_ASCL_fast_CA_sys    <B,R,API_polar>;
	friend Decoder_polar_ASCL_MEM_fast_CA_sys<B,R,API_polar>;

protected:
	const int             m;            // graph depth
	      mipp::vector<R> l;            // lambda, LR or LLR
	      mipp::vector<B> s;            // bits, partial sums
	      mipp::vector<B> s_bis;        // bits, partial sums
	const mipp::vector<B> &frozen_bits; // frozen bits

	const tools::Pattern_polar_parser<B> polar_patterns;

public:
	Decoder_polar_SC_fast_sys(const int& K, const int& N, const mipp::vector<B>& frozen_bits,
	                          const int n_frames = 1, const std::string name = "Decoder_polar_SC_fast_sys");

	Decoder_polar_SC_fast_sys(const int& K, const int& N, const mipp::vector<B>& frozen_bits,
	                          const std::vector<tools::Pattern_polar_i*> polar_patterns,
	                          const int idx_r0, const int idx_r1,
	                          const int n_frames = 1, const std::string name = "Decoder_polar_SC_fast_sys");

	virtual ~Decoder_polar_SC_fast_sys();

protected:
	        void _load       (const R *Y_N                            );
	virtual void _hard_decode(const R *Y_N, B *V_K, const int frame_id);
	        void _store      (              B *V_K                    );

	virtual void recursive_decode(const int off_l, const int off_s, const int reverse_depth, int &node_id);
};
}
}

#include "Decoder_polar_SC_fast_sys.hxx"

#endif /* DECODER_POLAR_SC_FAST_SYS_ */
