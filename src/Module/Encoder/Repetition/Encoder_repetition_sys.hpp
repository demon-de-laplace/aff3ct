#ifndef ENCODER_REPETITION_SYS_HPP_
#define ENCODER_REPETITION_SYS_HPP_

#include <vector>
#include <mipp.h>

#include "../Encoder_sys.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int>
class Encoder_repetition_sys : public Encoder_sys<B>
{
protected:
	const int rep_count; // number of repetition

	const bool buffered_encoding;
	
public:
	Encoder_repetition_sys(const int& K, const int& N, const bool buffered_encoding = true, const int n_frames = 1,
	                       const std::string name = "Encoder_repetition_sys");
	virtual ~Encoder_repetition_sys() {}

protected:
	virtual void _encode_sys(const B *U_K, B *par, const int frame_id);
	virtual void _encode    (const B *U_K, B *X_N, const int frame_id);
};
}
}

#endif // ENCODER_REPETITION_SYS_HPP_
