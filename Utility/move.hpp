#ifndef MOVE_HPP_
#define MOVE_HPP_

#include <type_traits>

namespace my {
	
	template <typename T>
	decltype(auto) move(T&& arg) {
		using ReturnType = typename std::remove_reference<T>::type&&;
		return static_cast<ReturnType>(arg);
	}

}

#endif //MOVE_HPP_
