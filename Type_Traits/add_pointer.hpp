#ifndef ADD_POINTER_HPP_
#define ADD_POINTER_HPP_

#include "remove_reference.hpp"
#include "type_identity.hpp"

namespace my {
	
	template <typename T>
	auto try_add_pointer(int) -> type_identity<typename remove_reference<T>::type*>;

	template <typename T>
	auto try_add_pointer(...) -> type_identity<T>;

	template <typename T>
	struct add_pointer : decltype(try_add_pointer<T>(0)) {};
	
	template <typename T>
	using add_pointer_t = typename add_pointer<T>::type;
}

#endif //ADD_POINTER_HPP_
