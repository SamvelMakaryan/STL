#ifndef REMOVE_CONST_HPP_
#define REMOVE_CONST_HPP_

namespace my {

	template <typename T>
	struct remove_const {
		using type = T;
	};
	
	template <typename T>
	struct remove_const<const T> {
		using type = T;
	};

	template <typename T>
	using remove_const_t = typename remove_const<T>::type;
}

#endif //REMOVE_CV_HPP_
