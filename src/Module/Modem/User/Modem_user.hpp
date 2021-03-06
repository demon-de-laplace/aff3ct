#ifndef MODEM_USER_HPP_
#define MODEM_USER_HPP_

#include <complex>
#include <vector>
#include <mipp.h>

#include "Tools/Math/max.h"

#include "../Modem.hpp"

namespace aff3ct
{
namespace module
{
template <typename B = int, typename R = float, typename Q = R, tools::proto_max<Q> MAX = tools::max_star>
class Modem_user : public Modem<B,R,Q>
{
private:
	const int bits_per_symbol;
	const int nbr_symbols;
	R sqrt_es;
	const bool disable_sig2;
	mipp::vector<std::complex<R>> constellation;

public:
	Modem_user(const int N, const R sigma = (R)1, const int bits_per_symbol = 2, const std::string const_path = "",
	           const bool disable_sig2 = false, const int n_frames = 1, const std::string name = "Modem_user");
	virtual ~Modem_user();

	static int size_mod(const int N, const int bps)
	{
		return Modem<B,R,Q>::get_buffer_size_after_modulation(N, bps, 0, 1, true);
	}

	static int size_fil(const int N, const int bps)
	{
		return Modem<B,R,Q>::get_buffer_size_after_filtering(N, bps, 0, 1, true);
	}

protected:
	void   _modulate           (const B *X_N1,                              R *X_N2, const int frame_id);
	void     _filter           (const R *Y_N1,                              R *Y_N2, const int frame_id);
	void _demodulate           (const Q *Y_N1,                              Q *Y_N2, const int frame_id);
	void _demodulate_with_gains(const Q *Y_N1, const R *H_N,                Q *Y_N2, const int frame_id);
	void _demodulate           (const Q *Y_N1,               const Q *Y_N2, Q *Y_N3, const int frame_id);
	void _demodulate_with_gains(const Q *Y_N1, const R *H_N, const Q *Y_N2, Q *Y_N3, const int frame_id);
};
}
}

#include "Modem_user.hxx"

#endif // MODEM_USER_HPP_
