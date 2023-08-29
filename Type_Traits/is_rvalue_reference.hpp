#ifndef IS_RVALUE_REFERENCE_HPP_
#define IS_RVALUE_REFERENCE_HPP_

#include "integral_constant.hpp"

namespace my {
	
	template <typename T>
	struct is_rvalue_reference : false_type {};
	
	template <typename T>
	struct is_rvalue_reference<T&&> : true_type {};
	
	template <typename T>
	inline constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value;

}

#endif //IS_RVALUE_REFERENCE_HPP_
