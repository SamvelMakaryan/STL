#ifndef VECTOR_BOOL_ITERATOR_
#define VECTOR_BOOL_ITERATOR_
#include "Vector_bool.hpp"

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator::iterator(const iterator&) = default;

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator::iterator(unsigned char* ptr)
 : ptr(ptr),
   index(0) {}

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator::iterator(unsigned char* ptr, size_t index)
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
constexpr size_t Vector<bool, Alloc>::iterator::operator-(iterator oth) const {
	return (oth.ptr - ptr) + (oth.index - index);
	return (oth.ptr - ptr) + (oth.index - index);
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

#endif //VECTOR_BOOL_ITERATOR_