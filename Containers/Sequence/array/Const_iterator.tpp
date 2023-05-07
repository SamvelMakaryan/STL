#ifndef CONST_ITERATOR_TPP_
#define CONST_ITERATOR_TPP_
#include "Array.hpp"

template <typename T, size_t N>
constexpr Array<T, N>::const_iterator::const_iterator(const T* ptr) 
: m_ptr(ptr) {}

template <typename T, size_t N>
constexpr Array<T, N>::const_iterator::const_iterator(const iterator& it) 
: m_ptr(&(*it)) {}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator& Array<T, N>::const_iterator::operator++() {
	++m_ptr; 
	return *this;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::const_iterator::operator++(int) {
	const_iterator tmp = *this; 
	++m_ptr; 
	return tmp;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator& Array<T, N>::const_iterator::operator--() {
	--m_ptr; 
	return *this;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::const_iterator::operator--(int) {
	const_iterator tmp = *this; 
	--m_ptr; 
	return tmp;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::const_iterator::operator+(size_t n) const {
	return const_iterator(m_ptr + n);
} 

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::const_iterator::operator-(size_t n) const {
	return const_iterator(m_ptr - n);
}

template <typename T, size_t N>
constexpr size_t Array<T, N>::const_iterator::operator-(const_iterator& it) const { 
	return (it.m_ptr - m_ptr);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator& Array<T, N>::const_iterator::operator+=(size_t n) {
	m_ptr += n; 
	return *this;
} 

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator& Array<T, N>::const_iterator::operator-=(size_t n) {
	m_ptr -= n; 
	return *this;
} 

template <typename T, size_t N>
constexpr bool Array<T, N>::const_iterator::operator!=(const const_iterator& oth) const {
	return m_ptr != oth.m_ptr;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::const_iterator::operator==(const const_iterator& oth) const {
	return m_ptr == oth.m_ptr;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::const_iterator::operator<(const const_iterator& oth) const {
	if (m_ptr < oth.m_ptr) {
		return true;
	} 
	return false;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::const_iterator::operator>(const const_iterator& oth) const {
	if (m_ptr > oth.m_ptr) {
		return true;
	} 
	return false;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::const_iterator::operator<=(const const_iterator& oth) const {
if (m_ptr <= oth.m_ptr) {
		return true;
	} 
	return false;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::const_iterator::operator>=(const const_iterator& oth) const {
	if (m_ptr >= oth.m_ptr) {
		return true;
	}
	return false;
}

template <typename T, size_t N>
constexpr const T& Array<T, N>::const_iterator::operator*() const {
	return *m_ptr;
}

#endif //CONST_ITERATOR_TPP_