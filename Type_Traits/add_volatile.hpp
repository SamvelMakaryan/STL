#ifndef ADD_VOLATILE_HPP_
#define ADD_VOLATILE_HPP_

namespace my {

	template <typename T>
	struct add_volatile {
		using type = volatile T;
	};
	
	template <typename T>
	using add_volatile_t = typename add_volatile<T>::type;
}

#endif //ADD_VOLATILE_HPP_
