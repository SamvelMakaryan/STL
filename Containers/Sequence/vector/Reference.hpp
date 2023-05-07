#ifndef REFERENCE_HPP_
#define REFERENCE_HPP_
#include "Vector_bool.hpp"

template <typename Alloc>
constexpr  Vector<bool, Alloc>::reference::reference(unsigned char* byte, size_t offset)
 : byte(byte),
   offset(offset) {}

template <typename Alloc>
constexpr  Vector<bool, Alloc>::reference::reference(const reference&) = default;

template <typename Alloc>
constexpr Vector<bool, Alloc>::reference::operator bool() const noexcept {
    return ((*byte) & (1 << offset));
}

template <typename Alloc>
constexpr typename Vector<bool, Alloc>::reference::reference& Vector<bool, Alloc>::reference::operator=(bool val) noexcept {
    if (val) {
        *byte |= (1 << offset);
    } else {
        *byte &= ~(1 << offset);
    }
    return *this;
}

template <typename Alloc>
constexpr typename Vector<bool, Alloc>::reference::reference& Vector<bool, Alloc>::reference::operator=(const reference& rhs) noexcept {
    return operator=(static_cast<bool>(rhs));
}

#endif //REFERENCE_HPP_