#ifndef ADD_RVALUE_REFERENCE_HPP_
#define ADD_RVALUE_REFERENCE_HPP_

#include "type_identity.hpp"

namespace my {
	
	template <typename T>
	auto try_add_rvalue_reference(int) -> type_identity<T&&>;

	template <typename T>
	auto try_add_rvalue_reference(...) -> type_identity<T>;

	template <typename T>
	struct add_rvalue_reference : decltype(try_add_rvalue_reference<T>(0)) {};
	
	template <typename T>
	using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
}

#endif //ADD_RVALUE_REFERENCE_HPP_
