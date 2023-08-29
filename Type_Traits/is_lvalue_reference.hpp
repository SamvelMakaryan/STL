#ifndef IS_LVALUE_REFERENCE_HPP_
#define IS_LVALUE_REFERENCE_HPP_

#include "integral_constant.hpp"

namespace my {
	
	template <typename T>
	struct is_lvalue_reference : false_type {};
	
	template <typename T>
	struct is_lvalue_reference<T&> : true_type {};
	
	template <typename T>
	inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

}

#endif //IS_LVALUE_REFERENCE_HPP_
