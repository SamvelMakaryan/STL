#ifndef VECTOR_BOOL_TPP_
#define VECTOR_BOOL_TPP_
#include "Vector_bool.hpp"

template <typename Alloc>
constexpr Vector<bool, Alloc>::Vector() noexcept(noexcept(Alloc()))
 : m_size(0),
   m_cap(0),
   m_buf(nullptr),
   m_allocator(Alloc()) {}

template <typename Alloc>
constexpr Vector<bool, Alloc>::Vector(const Alloc& allocator) noexcept
: m_size(0),
  m_cap(0),
  m_buf(nullptr),
  m_allocator(allocator) {}

template <typename Alloc>
constexpr Vector<bool, Alloc>::Vector(size_t n, const Alloc& allocator)
 : m_allocator(allocator),
   m_size(n),
   m_cap(n),
   m_buf(m_allocator.allocate((m_cap + 7) / 8)) {}

template <typename Alloc>
constexpr Vector<bool, Alloc>::Vector(size_t n, bool val, const Alloc& allocator)
 : m_allocator(allocator),
   m_size(n),
   m_cap(n),
   m_buf(m_allocator.allocate((m_cap + 7) / 8))
{
	for (size_t i = 0; i < m_size; ++i) {
		size_t offset = i % 8;
		size_t byte = i / 8;
		if (val) {
			*(m_buf + byte) |= (1 << offset);
		}	
		else {
			*(m_buf + byte) &= ~(1 << offset);
		}
	}
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::Vector(std::initializer_list<bool> init, const Alloc& allocator)
 : m_allocator(allocator),
   m_size(init.size()),
   m_cap(m_size),
   m_buf(m_allocator.allocate((m_cap + 7) / 8)) 
{
	size_t count = 0;
	for (auto& i : init) {
		size_t offset = count % 8;
		size_t byte = count / 8; 
		if (i) {
			*(m_buf + byte) |= (1 << offset);
			// std::cout << (*(m_buf + byte) |= (1 << offset)) << std::endl;
		}
		else  {
			*(m_buf + byte) &= ~(1 << offset);
		}
		++count;
	}
}
	
template <typename Alloc>
constexpr Vector<bool, Alloc>::Vector(const Vector<bool, Alloc>& oth)
 : m_allocator(oth.m_allocator),
   m_size(oth.m_size),
   m_cap(oth.m_cap),
   m_buf(m_allocator.allocate((m_cap + 7) / 8))
{
	for (int i = 0; i < m_size ; ++i) {
		size_t offset = i % 8;
		size_t byte = i / 8; 
		if (oth[i]) {
			*(m_buf + byte) |= (1 << offset);
		}
		else  {
			*(m_buf + byte) &= ~(1 << offset);
		}
	}
} 

template <typename Alloc>
constexpr Vector<bool, Alloc>::Vector(const Vector<bool, Alloc>& oth, const Alloc& allocator)
 : m_allocator(allocator),
   m_size(oth.m_size),
   m_cap(oth.m_cap),
   m_buf(m_allocator.allocate((m_cap + 7) / 8))
{
	for (int i = 0; i < m_size ; ++i) {
		size_t offset = i % 8;
		size_t byte = i / 8; 
		if (oth[i]) {
			*(m_buf + byte) |= (1 << offset);
		}
		else  {
			*(m_buf + byte) &= ~(1 << offset);
		}
	}
} 

template <typename Alloc>
constexpr Vector<bool, Alloc>::Vector(Vector<bool, Alloc>&& oth) noexcept
 : m_allocator(std::move(oth.m_allocator)),
   m_size(oth.m_size),
   m_cap(oth.m_cap), 
   m_buf(oth.m_buf)
{
	oth.m_buf = nullptr;
	oth.m_size = 0;
	oth.m_cap = 0;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::Vector(Vector<bool, Alloc>&& oth, const Alloc& allocator)
 : m_allocator(allocator),
   m_size(oth.m_size),
   m_cap(oth.m_cap), 
   m_buf(oth.m_buf)
{
	oth.m_buf = nullptr;
	oth.m_size = 0;
	oth.m_cap = 0;
}

template <typename Alloc>
template <typename InputIterator, typename>
constexpr Vector<bool, Alloc>::Vector(InputIterator first, InputIterator last, const Alloc& allocator)
: m_allocator(allocator)
{
	size_t count = 0;
	for (auto i = first; i != last; ++i) {
		++count;
	}
	m_cap = count;
	m_size = count;
	m_buf = m_allocator.allocate((m_cap + 7) / 8);
	size_t j = 0;
	for (auto i = first; i != last; ++i, ++j) {
		if (*i) {
			(m_buf[i / 8]) |= (1 << (i % 8));
		}
		else {
			(m_buf[i / 8]) &= ~(1 << (i % 8));
		}
	}
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::~Vector() {
	m_allocator.deallocate(m_buf, (m_cap+ 7) / 8);
	m_buf = nullptr;
}


template <typename Alloc>
constexpr  Vector<bool, Alloc>::reference Vector<bool, Alloc>::operator[](size_t n) {
	return reference(m_buf + n / 8, n % 8);
}

template <typename Alloc>
constexpr const Vector<bool, Alloc>::reference Vector<bool, Alloc>::operator[](size_t n) const {
	return reference(m_buf + n / 8, n % 8);
}

template <typename Alloc>
constexpr size_t Vector<bool, Alloc>::size() const noexcept {
	return m_size;
}

template <typename Alloc>
constexpr size_t Vector<bool, Alloc>::capacity() const noexcept {
	return m_cap;
}

template <typename Alloc>
constexpr const Vector<bool, Alloc>::reference Vector<bool, Alloc>::at(size_t n) const {
	if (n > m_size) {
		throw out_of_range("error : out of range");
	}
	return reference(m_buf + n / 8, n % 8);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::reference Vector<bool, Alloc>::at(size_t n) {
	if (n > m_size) {
		throw out_of_range("error : out of range");
	}
	return reference(m_buf + n / 8, n % 8);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::reference Vector<bool, Alloc>::front() {
    return reference(m_buf, 0);
}

template <typename Alloc>
constexpr const Vector<bool, Alloc>::reference Vector<bool, Alloc>::front() const {
    return reference(m_buf, 0);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::reference Vector<bool, Alloc>::back() {
    return operator[](m_size - 1);
}

template <typename Alloc>
constexpr const Vector<bool, Alloc>::reference Vector<bool, Alloc>::back() const {
    return operator[](m_size - 1);
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::empty() const noexcept {
	return !m_size;
}

template <typename Alloc>
constexpr size_t Vector<bool, Alloc>::max_size() const noexcept {
	return (std::numeric_limits<size_t>::max() / sizeof(bool));
}

template <typename Alloc>
constexpr void Vector<bool, Alloc>::_realloc(size_t n) {
	bool* tmp = m_allocator.allocate((n + 7) / 8);
	for (size_t i = 0; i < m_size; ++i) {
		tmp[i] = m_buf[i];
	}
	m_allocator.deallocate(m_buf, (m_cap + 7) / 8);
	m_buf = tmp;
	m_cap = n;
	tmp = nullptr;
}

template <typename Alloc>
constexpr void Vector<bool, Alloc>::resize(size_t n) {
	if (m_size == n) {
		return;
	}
	if (m_size > n ) {
		m_size = n;
		return;
	}
	if (n > m_cap) {
		_realloc(n * 2);
		m_size = n;
	}
	for (size_t i = m_size; i < n; ++i) {
		*(m_buf + i / 8) &= ~(1 << i % 8);
	}
}

template <typename Alloc>
constexpr void Vector<bool, Alloc>::resize(size_t n, bool val) {
	if (n == m_size) {
		return;
	}
	if (n < m_size) {
		m_size = n;
		return;
	}
	if (n > m_cap) {
		_realloc(n * 2);
	}
	for (size_t i = m_size; i < n; ++i) {
		operator[](i) = val;
	}
	m_size = n;
}

template <typename Alloc>
constexpr void Vector<bool, Alloc>::reserve(size_t n) {
	if (n <= m_cap) {
		return;
	}
	_realloc(n);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>& Vector<bool, Alloc>::operator=(const Vector& rhs) {
	if (this == &rhs) {
		return *this;
	}
	m_allocator.deallocate(m_buf, (m_cap + 7) / 8);
	m_size = rhs.m_size;
	m_cap = rhs.m_cap;
	m_buf = m_allocator.allocate((m_cap + 7) / 8);
	for (int i = 0; i < m_size; ++i) {
		m_buf[i] = rhs.m_buf[i];
	}
	return *this;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>& Vector<bool, Alloc>::operator=(Vector&& rhs) noexcept {
	m_allocator.deallocate(m_buf, (m_cap + 7) / 8);
	m_buf = rhs.m_buf;
	m_size = rhs.m_size;
	m_cap = rhs.m_cap;
	rhs.m_buf = nullptr;
	rhs.m_size = 0;
	rhs.m_cap = 0;
	return *this;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>& Vector<bool, Alloc>::operator=(std::initializer_list<bool> init) {
	// delete[] m_buf;
	m_allocator.deallocate(m_buf, (m_cap + 7) / 8);
	m_size = init.size();
	m_cap = m_size;
	m_buf = m_allocator.allocate(m_buf, (m_cap + 7) / 8);
	size_t count = 0;
	for (auto& val : init) {
		size_t byte = count / 8;
		size_t offset = count % 8;
		if (val) {
			*(m_buf + byte) |= (1 << offset);
		}
		else {
			*(m_buf + byte) &= ~(1 << offset);
		}
		++count;
	}
	return *this;
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::operator<(const Vector<bool, Alloc>& vec) const {
	for (size_t i = 0; i < m_size; ++i) {
		if (operator[](i) < vec[i]) {
			return true;
		}
	}
	return false;
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::operator>=(const Vector<bool, Alloc>& vec) const {
	return !(*this < vec);
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::operator==(const Vector<bool, Alloc>& vec) const {
	if (m_size != vec.m_size) {
		return false;
	}
	for (int i = 0; i < m_size; ++i) {
		if ((*this)[i] != vec[i]) {
			return false;
		}
	}
	return true;
}

template <typename Alloc>
constexpr auto Vector<bool, Alloc>::operator<=>(const Vector<bool, Alloc>& oth) const {
	auto result = (m_buf[0] <=> oth.m_buf[0]);
	for (size_t i = 0; i < m_size || i < oth.size(); ++i) {
		if (m_buf[i] != oth.m_buf[i]) {
			return m_buf[i] <=> oth.m_buf[i];
		}
	}
	return result;
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::operator!=(const Vector<bool, Alloc>& vec) const {
	return !(*this == vec);
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::operator<=(const Vector<bool, Alloc>& vec) const {
	if (*this < vec || *this == vec) {
		return true;
	}	
	return false;
}

template <typename Alloc>
constexpr bool Vector<bool, Alloc>::operator>(const Vector<bool, Alloc>& vec) const {
	return !(*this <= vec);
}

template <typename Alloc>
constexpr void Vector<bool, Alloc>::shrink_to_fit() {
	_realloc(m_size);
}

template <typename Alloc>
constexpr const bool* Vector<bool, Alloc>::data() const noexcept {
	return m_buf;
}

template <typename Alloc>
constexpr bool* Vector<bool, Alloc>::data() noexcept {
	return m_buf;
}

// template <typename Alloc>
// constexpr void Vector<bool, Alloc>::assign(size_t n, bool val) {
// 	// delete[] m_buf;
// 	m_size = n;
// 	m_cap = n;
// 	m_buf = new unsigned char [(m_cap + 7) / 8];
// 	for (int i = 0; i < m_size; ++i) {
// 		operator[](i) = val;
// 	}	
// }

// template <typename Alloc>
// constexpr void Vector<bool, Alloc>::assign(std::initializer_list<bool> init) {
// 	delete[] m_buf;
// 	m_size = init.size();
// 	m_cap = m_size;
// 	m_buf = new unsigned char [(m_cap + 7) / 8];
// 	int count = 0;
// 	for (auto& i : init) {
// 		operator[](count++) = i;
// 	}
// }

template <typename Alloc>
constexpr void Vector<bool, Alloc>::push_back(bool val) {
	if (m_cap == 0) {
		m_cap = 1;
		m_buf = m_allocator.allocate((m_cap + 7) / 8);
	}
	else if (m_size == m_cap) {
		_realloc(m_cap * 2);
	}
	operator[](m_size) = val;
	++m_size;
}
template <typename Alloc>
constexpr void Vector<bool, Alloc>::pop_back() {
	if (m_size == 0) {
		throw out_of_range("error : out of range");
	}
	--m_size;
}

template <typename Alloc>
constexpr void Vector<bool, Alloc>::swap(Vector<bool, Alloc>& oth) noexcept {
	Vector<bool> tmp = std::move(oth);
	oth = std::move(*this);
	*this = std::move(tmp);
}

template <typename Alloc>
constexpr void Vector<bool, Alloc>::clear() noexcept {
	m_size = 0;
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator Vector<bool, Alloc>::begin() noexcept {
	return iterator(m_buf);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::iterator Vector<bool, Alloc>::end() noexcept {
	return iterator(m_buf, m_size);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_iterator Vector<bool, Alloc>::begin() const noexcept {
	return const_iterator(m_buf);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_iterator Vector<bool, Alloc>::end() const noexcept {
	return const_iterator(m_buf, m_size);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::const_iterator Vector<bool, Alloc>::cbegin() const noexcept {
	return const_iterator(m_buf);
}
		
	
template <typename Alloc>
constexpr Vector<bool, Alloc>::const_iterator Vector<bool, Alloc>::cend() const noexcept {
	return const_iterator(m_buf, m_size);
}

template <typename Alloc>
constexpr Vector<bool, Alloc>::allocator_type Vector<bool, Alloc>::get_allocator() const noexcept {
	return m_allocator;
}
#endif
