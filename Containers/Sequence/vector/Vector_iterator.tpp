#ifndef VECTOR_ITERATOR_TPP
#define VECTOR_ITERATOR_TPP
#include "Vector.h"

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::iterator::iterator(T* ptr)
 : ptr(ptr) {}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator& Vector<T, Alloc>::iterator::operator++() { 
	++ptr;
	return *this;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::iterator::operator++(int) { 
	iterator tmp = *this;
	++ptr; 
	return tmp;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator& Vector<T, Alloc>::iterator::operator--() { 
	--ptr; 
	return *this;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::iterator::operator--(int) { 
	iterator tmp = *this; 
	--ptr; 
	return tmp;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::iterator::operator+(size_t n) const { 
	iterator tmp = *this; 
	tmp.ptr += n; 
	return tmp;
} 

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::iterator::operator-(size_t n) const { 
	iterator tmp = *this; 
	tmp.ptr -= n; 
	return tmp;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator& Vector<T, Alloc>::iterator::operator+=(size_t n) { 
	ptr += n; 
	return *this;
} 

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator& Vector<T, Alloc>::iterator::operator-=(size_t n) { 
	ptr -= n; 
	return *this;
} 

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::iterator::operator!=(const iterator& oth) const { 
	return ptr != oth.ptr;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::iterator::operator==(const iterator& oth) const { 
	return ptr == oth.ptr;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::iterator::operator<(const iterator& oth) const { 
	if (ptr < oth.ptr) { 
		return true;
	}
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::iterator::operator>(const iterator& oth) const {
	if (ptr > oth.ptr) {
		return true;
	}
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::iterator::operator<=(const iterator& oth) const {
	if (ptr <= oth.ptr) {
	return true;
	} 
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::iterator::operator>=(const iterator& oth) const {
	if (ptr >= oth.ptr) {
		return true;
	} 
	return false;
}

template <typename T, typename Alloc>
constexpr const T& Vector<T, Alloc>::iterator::operator*() const {
	return *ptr;
}

template <typename T, typename Alloc>
constexpr T& Vector<T, Alloc>::iterator::operator*() {
	return *ptr;
}

#endif