#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <sstream>
#include <algorithm>
#include <limits>
#include <mipp.h>

#include "Tools/Exception/exception.hpp"

namespace aff3ct
{
namespace tools
{
template <typename R> inline R           div2(R           val) { return val * (R)0.500; }
template <>           inline int         div2(int         val) { return val >> 1;       }
template <>           inline short       div2(short       val) { return val >> 1;       }
template <>           inline signed char div2(signed char val) { return val >> 1;       }

template <typename R> inline R           div4(R           val) { return val * (R)0.250; }
template <>           inline int         div4(int         val) { return val >> 2;       }
template <>           inline short       div4(short       val) { return val >> 2;       }
template <>           inline signed char div4(signed char val) { return val >> 2;       }

template <typename R> inline R           div8(R           val) { return val * (R)0.125; }
template <>           inline int         div8(int         val) { return val >> 3;       }
template <>           inline short       div8(short       val) { return val >> 3;       }
template <>           inline signed char div8(signed char val) { return val >> 3;       }

// init value depending on the domain
template <typename R>
constexpr R init_LR () { return (R)1; }

template <typename R>
constexpr R init_LLR() { return (R)0; }

// saturate values in function of the domain
template <typename R>
constexpr std::pair<R,R> sat_vals() { return std::make_pair(-std::numeric_limits<R>::infinity(), 
                                                             std::numeric_limits<R>::infinity()); }

template <>
constexpr std::pair<short, short> sat_vals() { return std::make_pair(-16382, 16382); }

template <>
constexpr std::pair<signed char, signed char> sat_vals() { return std::make_pair(-63, 63); }

// return the initial value for a bit
template <typename B>
constexpr B bit_init() { return (B)(((B)1) << (sizeof(B) * 8 -1)); }

// make a saturation on a the value "val"
template <typename T>
inline T saturate(const T val, const T min, const T max) { return std::min(std::max(val, min), max); }

// make a saturation on a full vector
template <typename T>
inline void saturate(mipp::vector<T> &array, const T min, const T max) 
{
	const auto loop_size = (int)array.size();
	for (auto i = 0; i < loop_size; i++)
		array[i] = saturate<T>(array[i], min, max);
}

template <typename B, typename R>
B sgn(R val) { return (B)((R(0) < val) - (val < R(0))); }


template <typename T>
constexpr bool is_power_of_2(T x)
{
	return (x > 0) && !(x & (x - 1));
}

template <typename R, typename function_type>
inline R integral(function_type func, const R min, const R max, const int number_steps)
{
	if (max < min)
	{
		std::stringstream message;
		message << "'max' has to be equal or greater than 'min' ('max' = " << max << ", 'min' = " << min << ").";
		throw invalid_argument(__FILE__, __LINE__, __func__, message.str());
	}

	if (number_steps <= 0)
	{
		std::stringstream message;
		message << "'number_steps' has to be greater than 0 ('number_steps' = " << number_steps << ").";
		throw invalid_argument(__FILE__, __LINE__, __func__, message.str());
	}

	R step = (max - min) / number_steps; // width of rectangle
	R area = (R)0;

	for (auto i = 0; i < number_steps; i++)
		area += func(min + ((R)i + (R)0.5) * step) * step;

	return area;
}
}
}

#endif /* MATH_UTILS_H */
