#ifndef VECTOR_BOOL_CONST_REVERSE_ITERATOR_TPP_
#define VECTOR_BOOL_CONST_REVERSE_ITERATOR_TPP_
#include "Vector_bool.hpp"  

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& oth) = default;

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator::const_reverse_iterator(const unsigned char* ptr)
 : ptr(ptr),
   index(0) {} 

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator::const_reverse_iterator(const unsigned char* ptr, size_t index) 
 : ptr(ptr),
   index(index) {}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator& Vector<bool, Alloc>::const_reverse_iterator::operator++() {
    --index;
    return *this;
}	

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator Vector<bool, Alloc>::const_reverse_iterator::operator++(int) {
    const_reverse_iterator tmp = *this;
    --tmp.index;
    return tmp;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator& Vector<bool, Alloc>::const_reverse_iterator::operator--() {
    ++index;
    return *this;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator Vector<bool, Alloc>::const_reverse_iterator::operator--(int) {
    const_reverse_iterator tmp = *this;
    ++tmp.index;
    return tmp;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator Vector<bool, Alloc>::const_reverse_iterator::operator+(size_t n) const {
    const_reverse_iterator tmp = *this;
    tmp.index -= n;
    return tmp;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator Vector<bool, Alloc>::const_reverse_iterator::operator-(size_t n) const {
    const_reverse_iterator tmp = *this;
    tmp.index += n;
    return tmp;
}

template <typename Alloc>
constexpr size_t Vector<bool, Alloc>::const_reverse_iterator::operator-(const_reverse_iterator oth) const { 
	return (oth.ptr - ptr) + (oth.index - index);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator& Vector<bool, Alloc>::const_reverse_iterator::operator+=(size_t n) {
    index -= n;
    return *this;
} 

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reverse_iterator& Vector<bool, Alloc>::const_reverse_iterator::operator-=(size_t n) {
    index += n;
    return *this;
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::const_reverse_iterator::operator!=(const const_reverse_iterator& oth) const {
    return !(operator==(oth));
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::const_reverse_iterator::operator==(const const_reverse_iterator& oth) const {
    return (ptr == oth.ptr && index == oth.index);
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::const_reverse_iterator::operator<(const const_reverse_iterator& oth) const {
    if (ptr < oth.ptr) { 
        return true;
    }
    else if (ptr > oth.ptr) { 
        return false;
    }
    else {
        return (index < oth.index);
    }
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::const_reverse_iterator::operator>(const const_reverse_iterator& oth) const {
    return !(*this == oth || *this < oth);
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::const_reverse_iterator::operator<=(const const_reverse_iterator& oth) const {
    return !(*this > oth);
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::const_reverse_iterator::operator>=(const const_reverse_iterator& oth) const {
    return !(*this < oth);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_reference Vector<bool, Alloc>::const_reverse_iterator::operator*() const {
    return reference(const_cast<unsigned char*>(ptr), index);
}

#endif //VECTOR_BOOL_CONST_REVERSE_ITERATOR_TPP_