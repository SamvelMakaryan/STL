#ifndef IS_ARITHMETIC_HPP_
#define IS_ARITHMETIC_HPP_

#include "is_integral.hpp"
#include "is_floating_point.hpp"

namespace my {
	
	template <typename T>
	struct is_arithmetic {
	    constexpr static bool value = is_floating_point_v<T> || is_integral_v<T>;
	};
	
	template <typename T>
	inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

}

#endif //IS_ARITHMETIC_HPP_
