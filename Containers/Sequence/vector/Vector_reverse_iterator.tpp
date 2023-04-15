#ifndef VECTOR_REVERSE_ITERATOR_TPP
#define VECTOR_REVERSE_ITERATOR_TPP
#include "Vector.hpp"

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::reverse_iterator::reverse_iterator(T* ptr)
 : ptr(ptr) {}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator& Vector<T, Alloc>::reverse_iterator::operator++() {
	--ptr; 
	return *this;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::reverse_iterator::operator++(int) {
	reverse_iterator tmp = *this; 
	--ptr; 
	return tmp;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator& Vector<T, Alloc>::reverse_iterator::operator--() {
	++ptr; 
	return *this;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::reverse_iterator::operator--(int) {
	reverse_iterator tmp = *this; 
	++ptr; 
	return tmp;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::reverse_iterator::operator+(size_t n) const {
	return reverse_iterator(ptr - n);
} 

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::reverse_iterator::operator-(size_t n) const {
	return reverse_iterator(ptr + n);
}


template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator& Vector<T, Alloc>::reverse_iterator::operator+=(size_t n) {
	ptr -= n; 
	return *this;
} 

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator& Vector<T, Alloc>::reverse_iterator::operator-=(size_t n) {
	ptr += n; 
	return *this;
} 

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::reverse_iterator::operator!=(const reverse_iterator& oth) const {
	return ptr != oth.ptr;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::reverse_iterator::operator==(const reverse_iterator& oth) const {
	return ptr == oth.ptr;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::reverse_iterator::operator<(const reverse_iterator& oth) const {
	if (ptr < oth.ptr) {
		return true;
	} 
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::reverse_iterator::operator>(const reverse_iterator& oth) const {
	if (ptr > oth.ptr) {
		return true;
	} 
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::reverse_iterator::operator<=(const reverse_iterator& oth) const {
	if (ptr <= oth.ptr) {
		return true;
	} 
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::reverse_iterator::operator>=(const reverse_iterator& oth) const {
	if (ptr >= oth.ptr) {
		return true;
	} 
	return false;
}

template <typename T, typename Alloc>
constexpr const T& Vector<T, Alloc>::reverse_iterator::operator*() const {
	return *ptr;
}

template <typename T, typename Alloc>
constexpr T& Vector<T, Alloc>::reverse_iterator::operator*() {
	return *ptr;
}

#endif