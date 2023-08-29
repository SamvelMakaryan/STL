#ifndef REMOVE_REFERENCE_HPP_
#define REMOVE_REFERENCE_HPP_

namespace my {

	template <typename T>
	struct remove_reference {
		using type = T;
	};
	
	template <typename T>
	struct remove_reference<T&> {
		using type = T;
	};

	template <typename T>
	struct remove_reference<T&&> {
		using type = T;
	};

	template <typename T>
	using remove_reference_t = typename remove_reference<T>::type;
}

#endif //REMOVE_REFERENCE_HPP_
