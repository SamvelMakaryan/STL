#ifndef REVERSE_ITERATOR_TPP_
#define REVERSE_ITERATOR_TPP_
#include "Array.hpp"

template <typename T, size_t N>
constexpr Array<T, N>::reverse_iterator::reverse_iterator(T* ptr)
 : m_ptr(ptr) {}

template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator& Array<T, N>::reverse_iterator::operator++() {
	--m_ptr; 
	return *this;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator Array<T, N>::reverse_iterator::operator++(int) {
	reverse_iterator tmp = *this; 
	--m_ptr; 
	return tmp;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator& Array<T, N>::reverse_iterator::operator--() {
	++m_ptr; 
	return *this;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator Array<T, N>::reverse_iterator::operator--(int) {
	reverse_iterator tmp = *this; 
	++m_ptr; 
	return tmp;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator Array<T, N>::reverse_iterator::operator+(size_t n) const {
	return reverse_iterator(m_ptr - n);
} 

template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator Array<T, N>::reverse_iterator::operator-(size_t n) const {
	return reverse_iterator(m_ptr + n);
}


template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator& Array<T, N>::reverse_iterator::operator+=(size_t n) {
	m_ptr -= n; 
	return *this;
} 

template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator& Array<T, N>::reverse_iterator::operator-=(size_t n) {
	m_ptr += n; 
	return *this;
} 

template <typename T, size_t N>
constexpr bool Array<T, N>::reverse_iterator::operator!=(const reverse_iterator& oth) const {
	return m_ptr != oth.m_ptr;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::reverse_iterator::operator==(const reverse_iterator& oth) const {
	return m_ptr == oth.m_ptr;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::reverse_iterator::operator<(const reverse_iterator& oth) const {
	if (m_ptr < oth.m_ptr) {
		return true;
	} 
	return false;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::reverse_iterator::operator>(const reverse_iterator& oth) const {
	if (m_ptr > oth.m_ptr) {
		return true;
	} 
	return false;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::reverse_iterator::operator<=(const reverse_iterator& oth) const {
	if (m_ptr <= oth.m_ptr) {
		return true;
	} 
	return false;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::reverse_iterator::operator>=(const reverse_iterator& oth) const {
	if (m_ptr >= oth.m_ptr) {
		return true;
	} 
	return false;
}

template <typename T, size_t N>
constexpr const T& Array<T, N>::reverse_iterator::operator*() const {
	return *m_ptr;
}

template <typename T, size_t N>
constexpr T& Array<T, N>::reverse_iterator::operator*() {
	return *m_ptr;
}

#endif //REVERSE_ITERATOR_TPP_