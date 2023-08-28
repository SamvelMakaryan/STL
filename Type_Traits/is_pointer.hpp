#ifndef IS_POINTER_HPP_
#define IS_POINTER_HPP_

#include "integral_constant.hpp"

namespace my {
	
	template <typename T>
	struct is_pointer : false_type {};
	
	template <typename T>
	struct is_pointer<T*> : true_type {};
	
	template <typename T>
	inline constexpr bool is_pointer_v = is_pointer<T>::value;

}

#endif //IS_POINTER_HPP_
