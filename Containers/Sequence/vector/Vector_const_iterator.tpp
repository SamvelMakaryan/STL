#ifndef VECTOR_CONST_ITERATOR_TPP_
#define VECTOR_CONST_ITERATOR_TPP_
#include "Vector.hpp"

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::const_iterator::const_iterator(const T* ptr) 
: ptr(ptr) {}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::const_iterator::const_iterator(const iterator& it) 
: ptr(&(*it)) {}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator& Vector<T, Alloc>::const_iterator::operator++() {
	++ptr; 
	return *this;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::const_iterator::operator++(int) {
	const_iterator tmp = *this; 
	++ptr; 
	return tmp;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator& Vector<T, Alloc>::const_iterator::operator--() {
	--ptr; 
	return *this;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::const_iterator::operator--(int) {
	const_iterator tmp = *this; 
	--ptr; 
	return tmp;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::const_iterator::operator+(size_t n) const {
	return const_iterator(ptr + n);
} 

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::const_iterator::operator-(size_t n) const {
	return const_iterator(ptr - n);
}

template <typename T, typename Alloc>
constexpr size_t Vector<T, Alloc>::const_iterator::operator-(const_iterator& it) const { 
	return (it.ptr - ptr);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator& Vector<T, Alloc>::const_iterator::operator+=(size_t n) {
	ptr += n; 
	return *this;
} 

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator& Vector<T, Alloc>::const_iterator::operator-=(size_t n) {
	ptr -= n; 
	return *this;
} 

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::const_iterator::operator!=(const const_iterator& oth) const {
	return ptr != oth.ptr;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::const_iterator::operator==(const const_iterator& oth) const {
	return ptr == oth.ptr;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::const_iterator::operator<(const const_iterator& oth) const {
	if (ptr < oth.ptr) {
		return true;
	} 
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::const_iterator::operator>(const const_iterator& oth) const {
	if (ptr > oth.ptr) {
		return true;
	} 
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::const_iterator::operator<=(const const_iterator& oth) const {
if (ptr <= oth.ptr) {
		return true;
	} 
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::const_iterator::operator>=(const const_iterator& oth) const {
	if (ptr >= oth.ptr) {
		return true;
	}
	return false;
}

template <typename T, typename Alloc>
constexpr const T& Vector<T, Alloc>::const_iterator::operator*() const {
	return *ptr;
}

#endif //VECTOR_CONST_ITERATOR_TPP_