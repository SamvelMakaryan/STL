#ifndef REMOVE_VOLATILE_HPP_
#define REMOVE_VOLATILE_HPP_

namespace my {

	template <typename T>
	struct remove_volatile {
		using type = T;
	};
	
	template <typename T>
	struct remove_volatile<volatile T> {
		using type = T;
	};

	template <typename T>
	using remove_volatile_t = typename remove_volatile<T>::type;
}

#endif //REMOVE_VOLATILE_HPP_
