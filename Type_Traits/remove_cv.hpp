#ifndef REMOVE_CV_HPP_
#define REMOVE_CV_HPP_

namespace my {

	template <typename T>
	struct remove_cv {
		using type = T;
	};
	
	template <typename T>
	struct remove_cv<const T> {
		using type = T;
	};

	template <typename T>
	struct remove_cv<volatile T> {
		using type = T;
	};

	template <typename T>
	struct remove_cv<const volatile T> {
		using type = T;
	};

	template <typename T>
	using remove_cv_t = typename remove_cv<T>::type;
}

#endif //REMOVE_CV_HPP_
