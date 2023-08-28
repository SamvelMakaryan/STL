#ifndef IS_VOID_HPP_
#define IS_VOID_HPP_

#include "integral_constant.hpp"

namespace my {

	template <typename T>
	struct is_void : false_type {};
	
	template <>
	struct is_void<void> : true_type {};

	template <typename T>
	inline constexpr bool is_void_v = is_void<T>::value;
}

#endif //IS_VOID_HPP_
