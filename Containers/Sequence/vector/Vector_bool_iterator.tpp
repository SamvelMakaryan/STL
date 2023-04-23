#ifndef VECTOR_BOOL_ITERATOR
#define VECTOR_BOOL_ITERATOR
#include "Vector_bool.hpp"

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator::iterator(const iterator&) = default;

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator::iterator(bool* ptr)
 : ptr(ptr),
   index(0) {}

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator::iterator(bool* ptr, size_t index)
 : ptr(ptr),
   index(index) {}

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator& Vector<bool, Alloc>::iterator::operator++() { 
    ++index;
    return *this;
}	

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator Vector<bool, Alloc>::iterator::operator++(int) { 
    iterator tmp = *this; 
    ++index; 
    return tmp;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator& Vector<bool, Alloc>::iterator::operator--() { 
    --index; 
    return *this;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator Vector<bool, Alloc>::iterator::operator--(int) { 
    iterator tmp = *this; 
    --index; 
    return tmp;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator Vector<bool, Alloc>::iterator::operator+(size_t n) const { 
    iterator tmp = *this; 
    tmp.index+= n; 
    return tmp;
} 

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator Vector<bool, Alloc>::iterator::operator-(size_t n) const { 
    iterator tmp = *this; 
    tmp.index -= n; 
    return tmp;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator& Vector<bool, Alloc>::iterator::operator+=(size_t n) {  
    index += n; 
    return *this;
} 

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator& Vector<bool, Alloc>::iterator::operator-=(size_t n) {  
    index -= n; 
    return *this;
} 

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::iterator::operator!=(const iterator& oth) const { 
    return !(operator==(oth));
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::iterator::operator==(const iterator& oth) const { 
    return (ptr == oth.ptr && index == oth.index);
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::iterator::operator<(const iterator& oth) const { 
    if (*(*this) < *oth) { 
        return true;
    } 
    return false;
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::iterator::operator>(const iterator& oth) const { 
    return !(*this == oth || *this < oth);
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::iterator::operator<=(const iterator& oth) const { 
    return !(*this > oth); 
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::iterator::operator>=(const iterator& oth) const { 
    return !(*this < oth);
}

template <typename Alloc>
constexpr typename Vector<bool, Alloc>::reference Vector<bool, Alloc>::iterator::operator*() {
    return reference(ptr, index);
}

template <typename Alloc>
constexpr Vector<bool,Alloc>::const_reference Vector<bool, Alloc>::iterator::operator*() const { 
    return reference(ptr, index);
}

#endif