#include <algorithm>
#include <cmath>
#include <sstream>

#include "Tools/Exception/exception.hpp"
#include "Tools/Math/utils.h"

#include "Quantizer_tricky.hpp"

using namespace aff3ct::module;
using namespace aff3ct::tools;

template <typename R, typename Q>
Quantizer_tricky<R,Q>
::Quantizer_tricky(const int N, const R& sigma, const int n_frames, const std::string name)
: Quantizer<R,Q>(N, n_frames, name),
  val_max(((1 << ((sizeof(Q) * 8) -2))) + ((1 << ((sizeof(Q) * 8) -2)) -1)),
  val_min(-val_max),
  delta_inv((R)0),
  sigma(sigma)
{
}

namespace aff3ct
{
namespace module
{
template <>
Quantizer_tricky<float,float>
::Quantizer_tricky(const int N, const float& sigma, const int n_frames, const std::string name)
: Quantizer<float,float>(N, n_frames, name), val_max(0), val_min(0), delta_inv(0.f), sigma(sigma) {}
}
}

namespace aff3ct
{
namespace module
{
template <>
Quantizer_tricky<double,double>
::Quantizer_tricky(const int N, const double& sigma, const int n_frames, const std::string name)
: Quantizer<double,double>(N, n_frames, name), val_max(0), val_min(0), delta_inv(0.f), sigma(sigma) {}
}
}

template <typename R, typename Q>
Quantizer_tricky<R,Q>
::Quantizer_tricky(const int N, const short& saturation_pos, const R& sigma, const int n_frames, const std::string name)
: Quantizer<R,Q>(N, n_frames, name),
  val_max(((1 << (saturation_pos -2))) + ((1 << (saturation_pos -2)) -1)),
  val_min(-val_max),
  delta_inv((R)0),
  sigma(sigma)
{
	if (sizeof(Q) * 8 < (unsigned) saturation_pos)
	{
		std::stringstream message;
		message << "'saturation_pos' has to be equal or smaller than 'sizeof(Q)' * 8 ('saturation_pos' = "
		        << saturation_pos << ", 'sizeof(Q)' = " << sizeof(Q) << ").";
		throw invalid_argument(__FILE__, __LINE__, __func__, message.str());
	}
}

namespace aff3ct
{
namespace module
{
template <>
Quantizer_tricky<float,float>
::Quantizer_tricky(const int N, const short& saturation_pos, const float& sigma, const int n_frames, 
                   const std::string name)
: Quantizer<float,float>(N, n_frames, name), val_max(0), val_min(0), delta_inv(0.f), sigma(sigma) {}
}
}

namespace aff3ct
{
namespace module
{
template <>
Quantizer_tricky<double,double>
::Quantizer_tricky(const int N, const short& saturation_pos, const double& sigma, const int n_frames, 
                   const std::string name)
: Quantizer<double,double>(N, n_frames, name), val_max(0), val_min(0), delta_inv(0.f), sigma(sigma) {}
}
}

template <typename R, typename Q>
Quantizer_tricky<R,Q>
::Quantizer_tricky(const int N, const float min_max, const R& sigma, const int n_frames, const std::string name)
: Quantizer<R,Q>(N, n_frames, name),
  val_max(((1 << ((sizeof(Q) * 8) -2))) + ((1 << ((sizeof(Q) * 8) -2)) -1)),
  val_min(-val_max),
  delta_inv((R)1.0 / ((R)std::abs(min_max) / (R)val_max)),
  sigma(sigma)
{
}

namespace aff3ct
{
namespace module
{
template <>
Quantizer_tricky<float,float>
::Quantizer_tricky(const int N, const float min_max, const float& sigma, const int n_frames, const std::string name)
: Quantizer<float,float>(N, n_frames, name), val_max(0), val_min(0), delta_inv(0.f), sigma(sigma) {}
}
}

namespace aff3ct
{
namespace module
{
template <>
Quantizer_tricky<double,double>
::Quantizer_tricky(const int N, const float min_max, const double& sigma, const int n_frames, const std::string name)
: Quantizer<double,double>(N, n_frames, name), val_max(0), val_min(0), delta_inv(0.f), sigma(sigma) {}
}
}

template <typename R, typename Q>
Quantizer_tricky<R,Q>
::Quantizer_tricky(const int N, const float min_max, const short& saturation_pos, const R& sigma, const int n_frames, 
                   const std::string name)
: Quantizer<R,Q>(N, n_frames, name),
  val_max(((1 << (saturation_pos -2))) + ((1 << (saturation_pos -2)) -1)),
  val_min(-val_max),
  delta_inv((R)1.0 / ((R)std::abs(min_max) / (R)val_max)),
  sigma(sigma)
{
	if (sizeof(Q) * 8 < (unsigned) saturation_pos)
	{
		std::stringstream message;
		message << "'saturation_pos' has to be equal or smaller than 'sizeof(Q)' * 8 ('saturation_pos' = "
		        << saturation_pos << ", 'sizeof(Q)' = " << sizeof(Q) << ").";
		throw invalid_argument(__FILE__, __LINE__, __func__, message.str());
	}
}

template <typename R, typename Q>
Quantizer_tricky<R,Q>
::~Quantizer_tricky()
{
}

template<typename R, typename Q>
void Quantizer_tricky<R,Q>
::process(const R *Y_N1, Q *Y_N2)
{
	const auto size = (unsigned)(this->N * this->n_frames);

	if (delta_inv == (R)0)
	{
		mipp::vector<R> tmp(size);
		R avg = 0;
		for (unsigned i = 0; i < size; i++)
		{
			tmp[i] = std::abs(Y_N1[i]);
			avg += tmp[i];
		}
		avg /= tmp.size();
		std::sort(tmp.begin(), tmp.end());

		delta_inv = (R)1.0 / ((R)std::abs(tmp[(tmp.size() / 10) * 8]) / (R)val_max);
	}

	for (unsigned i = 0; i < size; i++)
		Y_N2[i] = (Q)saturate(std::round(Y_N1[i] * delta_inv), (R)val_min, (R)val_max);
}

// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template class aff3ct::module::Quantizer_tricky<R_8,Q_8>;
template class aff3ct::module::Quantizer_tricky<R_16,Q_16>;
template class aff3ct::module::Quantizer_tricky<R_32,Q_32>;
template class aff3ct::module::Quantizer_tricky<R_64,Q_64>;
#else
template class aff3ct::module::Quantizer_tricky<R,Q>;
#endif
// ==================================================================================== explicit template instantiation
