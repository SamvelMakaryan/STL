#ifndef REMOVE_POINTER_HPP_
#define REMOVE_POINTER_HPP_

namespace my {

	template <typename T>
	struct remove_pointer {
		using type = T;
	};
	
	template <typename T>
	struct remove_pointer<T*> {
		using type = T;
	};

	template <typename T>
	struct remove_pointer<T* const> {
		using type = T;
	};

	template <typename T>
	struct remove_pointer<T* volatile> {
		using type = T;
	};
	template <typename T>

	struct remove_pointer<T* const volatile> {
		using type = T;
	};

	template <typename T>
	using remove_pointer_t = typename remove_pointer<T>::type;
}

#endif //REMOVE_POINTER_HPP_
