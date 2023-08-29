#ifndef ADD_LVALUE_REFERENCE_HPP_
#define ADD_LVALUE_REFERENCE_HPP_

#include "type_identity.hpp"

namespace my {
	
	template <typename T>
	auto try_add_lvalue_reference(int) -> type_identity<T&>;

	template <typename T>
	auto try_add_lvalue_reference(...) -> type_identity<T>;

	template <typename T>
	struct add_lvalue_reference : decltype(try_add_lvalue_reference<T>(0)) {};
	
	template <typename T>
	using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;
}

#endif //ADD_LVALUE_REFERENCE_HPP_
