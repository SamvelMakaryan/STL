#ifndef ADD_CONST_HPP_
#define ADD_CONST_HPP_

namespace my {

	template <typename T>
	struct add_const {
		using type = const T;
	};
	
	template <typename T>
	using add_const_t = typename add_const<T>::type;
}

#endif //ADD_CONST_HPP_
