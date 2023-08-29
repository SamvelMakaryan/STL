#ifndef IS_FUNCTION_HPP_
#define IS_FUNCTION_HPP_

#include "integral_constant.hpp"
#include "is_const.hpp"
#include "is_reference.hpp"

namespace my {
	
	template <typename T>
	struct is_function : integral_constant<bool, 
		!is_const<const T>::value && !is_reference<T>::value> {};
	
	template <typename T>
	inline constexpr bool is_function_v = is_function<T>::value;

};

#endif //IS_FUNCTION_HPP_
