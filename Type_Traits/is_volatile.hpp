#ifndef IS_VOLATILE_HPP_
#define IS_VOLATILE_HPP_

#include "integral_constant.hpp"

namespace my {
		
	template <typename T>
	struct is_volatile : false_type {};

	template <typename T>
	struct is_volatile<volatile T> : true_type {};

	template <typename T>
	inline constexpr bool is_volatile_v = is_volatile<T>::value;
	
}

#endif //IS_VOLATILE_HPP_
