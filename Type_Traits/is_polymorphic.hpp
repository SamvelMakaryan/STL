#ifndef IS_POLYMORPHIC_HPP_
#define IS_POLYMORPHIC_HPP_

#include "integral_constant.hpp"

namespace my {
		
	template <typename T>
	true_type detect_is_polymorphic(
		decltype(dynamic_cast<const volatile void*>(static_cast<T*>(nullptr))));
	
	template <typename T>
	false_type detect_is_polymorphic(...);

	template <typename T>
	struct is_polymorphic : decltype(detect_is_polymorphic<T>(nullptr)) {};

	template <typename T>
	inline constexpr bool is_polymorphic_v = is_polymorphic<T>::value;

}

#endif //IS_POLYMORPHIC_HPP_
