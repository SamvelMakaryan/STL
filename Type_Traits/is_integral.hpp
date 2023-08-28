#ifndef IS_INTEGRAL_HPP_
#define IS_INTEGRAL_HPP_

#include "integral_constant.hpp"

namespace my {
	
	template <typename T>
	struct is_integral : false_type {};
	
	template <>
	struct is_integral<bool> : true_type {};
	
	template <>
	struct is_integral<char> : true_type {};

	template <>
	struct is_integral<signed char> : true_type {};

	template <>
	struct is_integral<unsigned char> : true_type {};

	template <>
	struct is_integral<short> : true_type {};

	template <>
	struct is_integral<unsigned short> : true_type {};

	template <>
	struct is_integral<int> : true_type {};

	template <>
	struct is_integral<unsigned int> : true_type {};

	template <>
	struct is_integral<long> : true_type {};


	template <>
	struct is_integral<unsigned long> : true_type {};

	template <>
	struct is_integral<long long> : true_type {};

	template <>
	struct is_integral<unsigned long long> : true_type {};

	template <typename T>
	inline constexpr bool is_integral_v = is_integral<T>::value;

}

#endif //IS_INTEGRAL_HPP_
