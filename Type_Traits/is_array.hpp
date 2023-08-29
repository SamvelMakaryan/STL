#ifndef IS_ARRAY_HPP_
#define IS_ARRAY_HPP_

#include "integral_constant.hpp"

#include <cstddef>

namespace my {

	template <typename T>
	struct is_array : false_type {};
	
	template <typename T>
	struct is_array<T[]> : true_type {};

	template <typename T, std::size_t N>
	struct is_array<T[N]> : true_type {};

	template <typename T>
	inline constexpr bool is_array_v = is_array<T>::value;
}

#endif //IS_ARRAY_HPP_
