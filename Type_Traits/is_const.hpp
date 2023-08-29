#ifndef IS_CONST_HPP_
#define IS_CONST_HPP_

#include "integral_constant.hpp"

namespace my {
		
	template <typename T>
	struct is_const : false_type {};

	template <typename T>
	struct is_const<const T> : true_type {};

	template <typename T>
	inline constexpr bool is_const_v = is_const<T>::value;
	
}

#endif //IS_CONST_HPP_
