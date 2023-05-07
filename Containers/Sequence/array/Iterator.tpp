#ifndef ITERATOR_TPP_
#define ITERATOR_TPP_
#include "Array.hpp"

template <typename T, size_t N>
constexpr Array<T, N>::iterator::iterator(T* ptr)
 : m_ptr(ptr) {}

template <typename T, size_t N>
constexpr Array<T, N>::iterator::iterator(const iterator& it)
 : m_ptr(it.ptr) {}


template <typename T, size_t N>
constexpr typename Array<T, N>::iterator& Array<T, N>::iterator::operator++() { 
	++m_ptr;
	return *this;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::iterator::operator++(int) { 
	iterator tmp = *this;
	++m_ptr; 
	return tmp;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::iterator& Array<T, N>::iterator::operator--() { 
	--m_ptr; 
	return *this;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::iterator::operator--(int) { 
	iterator tmp = *this; 
	--m_ptr; 
	return tmp;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::iterator::operator+(size_t n) const { 
	return iterator(m_ptr + n);
} 

template <typename T, size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::iterator::operator-(size_t n) const { 
	return iterator(m_ptr - n);
}

template <typename T, size_t N>
constexpr size_t Array<T, N>::iterator::operator-(iterator& it) const { 
	return (it.m_ptr - m_ptr);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::iterator& Array<T, N>::iterator::operator+=(size_t n) { 
	m_ptr += n; 
	return *this;
} 

template <typename T, size_t N>
constexpr typename Array<T, N>::iterator& Array<T, N>::iterator::operator-=(size_t n) { 
	m_ptr -= n; 
	return *this;
} 

template <typename T, size_t N>
constexpr bool Array<T, N>::iterator::operator!=(const iterator& oth) const { 
	return m_ptr != oth.m_ptr;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::iterator::operator==(const iterator& oth) const { 
	return m_ptr == oth.m_ptr;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::iterator::operator<(const iterator& oth) const { 
	if (m_ptr < oth.m_ptr) { 
		return true;
	}
	return false;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::iterator::operator>(const iterator& oth) const {
	if (m_ptr > oth.m_ptr) {
		return true;
	}
	return false;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::iterator::operator<=(const iterator& oth) const {
	if (m_ptr <= oth.m_ptr) {
	return true;
	} 
	return false;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::iterator::operator>=(const iterator& oth) const {
	if (m_ptr >= oth.m_ptr) {
		return true;
	} 
	return false;
}

template <typename T, size_t N>
constexpr const T& Array<T, N>::iterator::operator*() const {
	return *m_ptr;
}

template <typename T, size_t N>
constexpr T& Array<T, N>::iterator::operator*() {
	return *m_ptr;
}

#endif //ITERATOR_TPP_