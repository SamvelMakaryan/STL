#ifndef IS_REFERENCE_HPP_
#define IS_REFERENCE_HPP_

#include "integral_constant.hpp"

namespace my {
	
	template <typename T>
	struct is_reference : false_type {};
	
	template <typename T>
	struct is_reference<T&> : true_type {};
	
	template <typename T>
	struct is_reference<T&&> : true_type {};

	template <typename T>
	inline constexpr bool is_reference_v = is_reference<T>::value;

}

#endif //IS_REFERENCE_HPP_
