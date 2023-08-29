#ifndef ADD_CV_HPP_
#define ADD_CV_HPP_

namespace my {

	template <typename T>
	struct add_cv {
		using type = const volatile T;
	};
	
	template <typename T>
	using add_cv_t = typename add_cv<T>::type;
}

#endif //ADD_CV_HPP_
