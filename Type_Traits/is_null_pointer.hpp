#ifndef IS_NULL_POINTER_HPP_
#define IS_NULL_POINTER_HPP_

#include "remove_cv.hpp"
#include "is_same.hpp"

#include <cstddef>

namespace my {

	template <typename T>
	struct is_null_pointer : is_same<std::nullptr_t, remove_cv_t<T>> {};
	
	template <typename T>
	inline constexpr bool is_null_pointer_v = is_null_pointer<T>::value;
}

#endif //IS_POINTER_HPP_
