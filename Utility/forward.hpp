#ifndef FORWARD_HPP_
#define FORWARD_HPP_

#include <type_traits>

namespace my {
    
    template <typename T>
    decltype(auto) forward(std::remove_reference<T>::type& arg) noexcept {
        return static_cast<T&&>(arg);
    }

}

#endif //FORWARD_HPP_