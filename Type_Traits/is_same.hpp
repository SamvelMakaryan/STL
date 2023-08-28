#ifndef IS_SAME_HPP_
#define IS_SAME_HPP_

#include "integral_constant.hpp"

namespace my {
	
	template <typename T, typename U>
	struct is_same : false_type {};
	
	template <typename T>
	struct is_same<T, T> : true_type {};
	
	template <typename T, typename U>
	inline constexpr bool is_same_v = is_same<T, U>::value;

}

#endif //IS_SAME_HPP_
