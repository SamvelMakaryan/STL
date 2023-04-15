#ifndef VECTOR_IMPLEMENTATION_TPP 
#define VECTOR_IMPLEMENTATION_TPP
#include "Vector.hpp" 

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector() noexcept(noexcept(Alloc()))
 : m_size(0),
   m_cap(0),
   m_buf(nullptr),
   m_allocator(Alloc()) {}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(const Alloc& allocator) noexcept
: m_allocator(allocator),
  m_size(0),
  m_cap(0),
  m_buf(nullptr) {}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(size_t n, const Alloc& allocator)
 : m_size(n),
   m_cap(n),
   m_allocator(allocator)
{
	m_buf = m_allocator.allocate(m_cap);
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(size_t n, const T& val, const Alloc& allocator)
 : m_size(n),
   m_cap(n),
   m_allocator(allocator)
{
	m_buf = m_allocator.allocate(m_cap);
	for (size_t i = 0; i < m_size; ++i) {
		m_allocator.construct(m_buf + i, val);
	}
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(const Vector& vec)
 : m_size(vec.m_size),
   m_cap(vec.m_cap)
{
	m_buf = m_allocator.allocate(m_cap);
	for (size_t i = 0; i < m_size; ++i) {
		m_allocator.construct(m_buf + i, vec.m_buf[i]);
	}
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(const Vector& vec, const Alloc& allocator)
 : m_allocator(allocator),
   m_size(vec.m_size),
   m_cap(vec.m_cap)
{
	m_buf = m_allocator.allocate(m_cap);
	for (size_t i = 0; i < m_size; ++i) {
		m_allocator.construct(m_buf + i, vec.m_buf[i]);
	}
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(Vector&& vec) noexcept
 : m_allocator(std::move(vec.m_allocator)),
   m_size(vec.m_size),
   m_cap(vec.m_cap),
   m_buf(vec.m_buf)
{
	vec.m_buf = nullptr;
	vec.m_size = 0;
	vec.m_cap = 0;
}

template <typename T, typename Alloc>
constexpr Vector<T,Alloc>::Vector(Vector&& vec, const Alloc& allocator) 
 : m_allocator(allocator),
   m_size(vec.m_size),
   m_cap(vec.m_cap),
   m_buf(vec.m_buf)
{
	vec.m_buf = nullptr;
	vec.m_size = 0;
	vec.m_cap = 0;
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(std::initializer_list<T> init, const Alloc& allocator)
 : m_allocator(allocator),
   m_size(init.size()),
   m_cap(m_size)
{
	m_buf = m_allocator.allocate(m_cap);
	size_t count = 0;
	for (auto& i : init) {
		m_allocator.construct(m_buf + count++, i);
	}
}

template <typename T, typename Alloc>
template <typename InputIterator, typename>
constexpr Vector<T, Alloc>::Vector(InputIterator first, InputIterator last, const Alloc& allocator) 
 : m_allocator(allocator)
{
	size_t count = 0;
	size_t j = 0;
	for (auto i = first; i != last; ++i) {
		++count;
	}
	m_cap = count;
	m_size = count;
	m_buf = m_allocator.allocate(m_cap);
	for (auto i = first ; i != last; ++i) {
		m_allocator.construct(m_buf + j++, *i);
	}
}
		
template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::~Vector() {
	for (size_t i = 0; i < m_size; ++i) {
		m_allocator.destroy(m_buf + i);
	}
	m_allocator.deallocate(m_buf, m_cap);
	m_buf = nullptr;
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>& Vector<T, Alloc>::operator=(const Vector & rhs) {
	if (this == &rhs) {
		return *this;
	}
	for (size_t i = 0; i < m_size; ++i) {
		m_allocator.destroy(m_buf + i);
	}
	m_allocator.deallocate(m_buf, m_cap);
	m_size = rhs.m_size;
	m_cap = rhs.m_cap;
	m_buf = m_allocator.allocate(m_cap);
	for(size_t i = 0; i < m_size; ++i) {
		m_allocator.construct(m_buf + i, rhs.m_buf[i]);
	}
	return *this;
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>& Vector<T, Alloc>::operator=(Vector && rhs) noexcept {
	for (size_t i = 0; i < m_size; ++i) {
		m_allocator.destroy(m_buf + i);
	}
	m_allocator.deallocate(m_buf, m_cap);
	m_buf = rhs.m_buf;
	m_size = rhs.m_size;
	m_cap = rhs.m_cap;
	rhs.m_buf = nullptr;
	rhs.m_size = 0;
	rhs.m_cap  = 0;
	return *this;
}
		
template <typename T, typename Alloc>
constexpr Vector<T, Alloc>& Vector<T, Alloc>::operator=(std::initializer_list<T> init) {
	for (size_t i = 0; i < m_size; ++i) {
		m_allocator.destroy(m_buf + i);
	}
	m_allocator.deallocate(m_buf, m_cap);
	m_size = init.size();
	m_cap = m_size * 2;
	m_buf = m_allocator.allocate(m_cap);
	size_t count = 0;
	for(auto& i : init) {
		m_allocator.construct(m_buf + count++, i);
	}
	return *this;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::operator==(const Vector<T, Alloc> & vec) const {
	if (vec.size() != this->size()) {
		return false;
	}
	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec.m_buf[i] != m_buf[i]) {
			return false;
		}
	}
	return true;
}

template <typename T, typename Alloc>
constexpr auto Vector<T, Alloc>::operator<=>(const Vector<T, Alloc> & oth) const {
	auto result = (m_buf[0] <=> oth.m_buf[0]);
	for (size_t i = 0; i < m_size || i < oth.size(); ++i) {
		if (m_buf[i] != oth.m_buf[i]) {
			return m_buf[i] <=> oth.m_buf[i];
		}
	}
	return result;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::operator!=(const Vector<T, Alloc> & vec) const {
	return !operator==(vec);
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::operator<(Vector<T, Alloc> & vec) const {
	for (size_t i = 0; i < m_size; ++i) {
		if (m_buf[i] < vec.m_buf[i]) {
			return true;
		}
	}
	return false;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::operator>=(Vector<T, Alloc> & vec) const {
	if (*this < vec) {
		return false;
	}
	return true;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::operator>(Vector<T, Alloc> & vec) const {
	if (*this < vec || *this == vec) {
		return false;
	}
	return true;
}

template <typename T, typename Alloc>
constexpr bool Vector<T, Alloc>::operator<=(Vector<T, Alloc> & vec) const {
	if (*this > vec) {
		return false;
	}
	return true;
}

template <typename T, typename Alloc>
constexpr const T& Vector<T, Alloc>::operator[](size_t n) const {
	return m_buf[n];
}

template <typename T, typename Alloc>
constexpr T& Vector<T, Alloc>::operator[](size_t n) {
	return m_buf[n];
}

template <typename T, typename Alloc>
constexpr size_t Vector<T, Alloc>::size() const noexcept {
	return m_size;
}

template <typename T, typename Alloc>
constexpr size_t Vector<T, Alloc>::max_size() const noexcept {
	return (std::numeric_limits<size_t>::max() / sizeof(T));
}

template <typename T, typename Alloc>
constexpr size_t Vector<T, Alloc>::capacity() const noexcept {
	return m_cap;
}
		
template <typename T, typename Alloc>
[[nodiscard]] constexpr bool Vector<T, Alloc>::empty() const noexcept {
	return !m_size;
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::resize(size_t n) {
	if (n == m_size) {
		return;
	}
	if (n < m_size) {
		for (size_t i = n; i < m_size; ++i) {
			m_allocator.destroy(m_buf + i);
		}
		m_size = n;
		return;
	}
	if (n > m_cap) {
		_realloc(n * 2);
	}
	for (size_t i = m_size; i < n; ++i) {
		m_allocator.construct(m_buf + i);
	}
	m_size = n;
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::resize(size_t n, const T& val) {
	if (n == m_size) {
		return;
	}
	if (n < m_size) {
		for (size_t i = m_size; i < n; ++i) {
			m_allocator.destroy(m_buf + i);
		}
		m_size = n;
		return;
	}
	if (n > m_cap) {
		_realloc(n * 2);
	}
	for (size_t i = m_size; i < n; ++i) {
		m_allocator.construct(m_buf + i, val);
	}
	m_size = n;
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::reserve(size_t n) {
	if (n <= m_cap) {
		return;
	}
	_realloc(n);
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::shrink_to_fit() {
	_realloc(m_size);
}

template <typename T, typename Alloc>
constexpr const T& Vector<T, Alloc>::front() const {
	return m_buf[0];
}

template <typename T, typename Alloc>
constexpr T& Vector<T, Alloc>::front() {
	return m_buf[0];
}

template <typename T, typename Alloc>
constexpr const T& Vector<T, Alloc>::back() const {
	return m_buf[m_size - 1];
}

template <typename T, typename Alloc>
constexpr T& Vector<T, Alloc>::back() {
	return m_buf[m_size - 1];
}
	
template <typename T, typename Alloc>
constexpr const T* Vector<T, Alloc>::data() const noexcept {
	return m_buf;
}

template <typename T, typename Alloc>
constexpr T* Vector<T, Alloc>::data() noexcept {
	return m_buf;
}

// template <typename T, typename Alloc>
// constexpr void Vector<T, Alloc>::assign(size_t n, const T& val) {
// 	delete[] m_buf;
// 	m_size = n;
// 	m_cap = n;
// 	m_buf = new T [m_cap];
// 	for (size_t i = 0; i < m_size; ++i) {
// 		m_buf[i] = val;
// 	}
// }

// template <typename T, typename Alloc>
// constexpr void Vector<T, Alloc>::assign(std::initializer_list<T> init) {
// 	delete[] m_buf;
// 	m_size = init.size();
// 	m_cap = m_size;
// 	m_buf = new T [m_cap];
// 	size_t count = 0;
// 	for (auto& i : init) {
// 		m_buf[count++] = i;
// 	}
// }

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::push_back(const T& val) {
	if (m_cap == 0) {
		m_cap = 1;
		m_buf = m_allocator.allocate(m_cap);
	}
	else if (m_size == m_cap) {
		_realloc(m_cap * 2);
	}
	m_allocator.construct(m_buf + m_size, val);
	++m_size;
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::push_back(T&& val) {
	if (m_cap == 0) {
		m_cap = 1;
		m_buf = m_allocator.allocate(m_cap);
	}
	else if (m_size == m_cap) {
		_realloc(m_cap * 2);
	}
	m_allocator.construct(m_buf + m_size, std::move(val));
	++m_size;
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::pop_back() {
	if (m_size == 0) {
		throw out_of_range("error : vector is empty");
	}
	m_allocator.destroy(m_buf + m_size - 1);
	--m_size;
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::swap(Vector<T, Alloc>& vec) noexcept {
	Vector<T, Alloc> tmp = std::move(vec);
	vec = std::move(*this);
	*this = std::move(tmp);
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::clear() noexcept {
	for (size_t i = m_size - 1; i >= 0; --i) {
		m_allocator.destroy(m_buf + i);
	}
	m_size = 0;
}

template <typename T, typename Alloc>
constexpr const T& Vector<T, Alloc>::at(size_t n) const {
	if (n >= m_size) {
		throw out_of_range("error : out of range");
	}
	return m_buf[n];
}
	
template <typename T, typename Alloc>
constexpr T& Vector<T, Alloc>::at(size_t n) {
	if (n >= m_size) {
		throw out_of_range("error : out of range");
	}
	return m_buf[n];
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::_realloc(size_t n) {
	T* tmp = m_allocator.allocate(n);
	for (size_t i = 0; i < m_size; ++i) {
		m_allocator.construct(tmp + i, std::move(m_buf[i]));
		m_allocator.destroy(m_buf + i);
	}
	m_allocator.deallocate(m_buf, m_cap);
	m_buf = tmp;
	m_cap = n;
	tmp = nullptr;
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::begin() noexcept {
	return iterator(m_buf);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::begin() const noexcept {
	return const_iterator(m_buf);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::end() noexcept {
	return iterator(m_buf + m_size);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::end() const noexcept { 
	return const_iterator(m_buf + m_size);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::cbegin() const noexcept {
	return const_iterator(m_buf);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::cend() const noexcept { 
	return const_iterator(m_buf + m_size);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::rbegin() noexcept {
	return reverse_iterator(m_buf + m_size - 1 );
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::rend() noexcept {
	return reverse_iterator(m_buf - 1);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_reverse_iterator Vector<T, Alloc>::crbegin() const noexcept {
	return const_reverse_iterator(m_buf + m_size - 1 );
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::const_reverse_iterator Vector<T, Alloc>::crend() const noexcept {
	return const_reverse_iterator(m_buf - 1);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(iterator it) {
	if (it > end() || it < begin()) {
		throw out_of_range("error : out of range");
	}
	size_t index = std::distance(it, begin()); 
		m_allocator.destroy(m_buf + index);
	for (size_t i = index + 1; i < m_size; ++i) {
		m_allocator.construct(m_buf + i - 1, std::move(m_buf[i]));
		m_allocator.destroy(m_buf + i);
	}
	--m_size;
	return iterator(m_buf + index);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(iterator first, iterator last) {
	if (first > last || first < begin() || last > end() || first > end() || last < begin()) {
		throw out_of_range("error : out of range");
	}
	size_t index = std::distance(first, begin());
	size_t count = std::distance(last, first);
	for (size_t i = 0; i < count; ++i) {
		m_allocator.destroy(m_buf + index + i);
	}
	for (int i = index ; i < m_size; ++i) {
		m_allocator.construct(m_buf + i, std::move(m_buf[i + count]));
		m_allocator.destroy(m_buf + i + count);
	}
	m_size -= count;
	return iterator(m_buf + index);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, const T& val) {
	if (it < begin() || it > end()) {
		throw out_of_range("error : out of range");
	}
	size_t index = std::distance(it, begin());
	if (m_cap == 0) {
		m_cap = 1;
		m_buf = m_allocator.allocate(m_cap);
	}
	else if (m_size == m_cap) {
		_realloc(m_cap * 2);
	}
	for (size_t i = m_size; i >= index + 1; --i) {
		m_allocator.construct(m_buf + i, std::move(m_buf[i - 1]));
		m_allocator.destroy(m_buf + i - 1);
	}
	m_allocator.construct(m_buf + index, val);
	++m_size;
	return iterator(m_buf + index);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, size_t n, const T& val) {
	if (it < begin() || it > end()) {
		throw out_of_range("error : out of range");
	}
	size_t index = std::distance(it, begin());
	if (m_cap == 0) {
		m_cap = n + 1;
		m_buf = m_allocator.allocate(m_cap);
	}
	else if (m_size + n >= m_cap) {
		_realloc((m_cap + n) * 2);
	}
	for (size_t i = m_size; i >= index + 1 ; --i) {
		m_allocator.construct(m_buf + i + n - 1, std::move(m_buf[i - 1]));
		m_allocator.destroy(m_buf + i - 1);
	}
	for (size_t i = index; i < index + n; ++i) {
		m_allocator.construct(m_buf + i, val);
	}
	m_size += n;
	return iterator(m_buf + index);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, iterator first, iterator last) {
	if (first > last  || it > end() || it < begin()) {
		throw out_of_range("error : out of range");
	}
	size_t count = std::distance(last, first);
	size_t index = std::distance(it, begin());
	if (m_cap == 0) {
		m_cap = count + 1;
		m_buf = m_allocator.allocate(m_cap);
	}
	else if (m_cap + count >= m_size) {
		_realloc((m_cap + count) * 2);
	}
	for (size_t i = m_size; i >= index + 1; --i) {
		m_allocator.construct(m_buf + i + count - 1, std::move(m_buf[i - 1]));
		m_allocator.destroy(m_buf + i - 1);
	}
	for (size_t i = index; i < index + count; ++i, ++first) {
		m_allocator.construct(m_buf + i, std::move(*first));
	}
	m_size += count;
	return iterator(m_buf + index);
}

template <typename T, typename Alloc>	
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, T&& val) {
	if (it < begin() || it > end()) {
		throw out_of_range("error : out of range");
	}
	size_t index = std::distance(it, begin());
	if (m_cap == 0) {
		m_cap = 1;
		m_buf = m_allocator.allocate(m_cap);
	}
	else if (m_cap == m_size) {
		_realloc(m_cap);
	}
	for (size_t i = m_size; i >= index + 1; --i) {
		m_allocator.construct(m_buf + i, std::move(m_buf[i - 1]));
		m_allocator.destroy(m_buf + i - 1);
	}
	m_allocator.construct(m_buf + index, std::move(val));
	++m_size;
	return iterator(m_buf + index);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, std::initializer_list<T> init) {
	if (it < begin() || it > end()) {
		throw out_of_range("error : out of range");
	}
	size_t size = init.size();
	size_t index = std::distance(it, begin());
	if (m_cap == 0) {
		m_cap = m_size + size + 1;
		m_buf = m_allocator.allocate(m_cap);
	}
	else if (m_size >= m_cap) {
		_realloc((m_cap + size) * 2);
	}
	size_t count = m_size - index;
	for (size_t i = m_size; i >= index + 1; --i) {
		m_allocator.construct(m_buf + i + size - 1, std::move(m_buf[i - 1]));
		m_allocator.destroy(m_buf + i - 1);
	}
	for (size_t i = 0; i < size; ++i) {
		m_allocator.construct(m_buf + index + i, std::move(*(init.begin() + i)));
	}
	m_size += size;
	return iterator(m_buf + index);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::allocator_type Vector<T, Alloc>::get_allocator() const noexcept {
	return m_allocator;
}

// template <typename T, typename Alloc>
// constexpr void Vector<T, Alloc>::assign(iterator first, iterator last) {
// 	// delete[] m_buf;
// 	for (size_t i = 0; i < m_size; ++i) {
// 		m_allocator.destroy(m_buf + i);
// 	}
// 	m_allocator.deallocate(m_buf, m_cap);
// 	size_t size = 0;
// 	for (auto i = first; i != last; ++i) {
// 		++size;
// 	}
// 	m_size = size;
// 	m_cap = m_size;
// 	// m_buf = new T [m_cap];
// 	m_buf = m_allocator.allocate(m_cap);
// 	size_t j = 0;
// 	for (auto i = first; i != last; ++i) {
// 		// m_buf[j++] = *i;
// 		m_allocator.constuct(m_buf + j++, *i);
// 	}
// }

template <typename T, typename Alloc>
template <typename... Args>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::emplace(const_iterator it, Args&&... args) {
	if (it > cend() || it < cbegin()) {
		throw out_of_range("error : out of range");
	}
	size_t index = std::distance(it, cbegin());
	if (m_cap == m_size) {
		_realloc(m_cap * 2);
	}
	for (size_t i = m_size; i >= index + 1; --i) {
		m_allocator.construct(m_buf + i, std::move(m_buf[i - 1]));
		m_allocator.destroy(m_buf + i - 1);
	}
	m_allocator.construct(m_buf + index, (args)...);
	++m_size;
	return iterator(m_buf + index);
}

template <typename T, typename Alloc>
template <typename... Args>
constexpr T& Vector<T, Alloc>::emplace_back(Args&&... args) {
	if (m_size == m_cap) {
		_realloc(m_cap * 2);
	}
	m_allocator.construct(m_buf + m_size, (args)...);
	++m_size;
	return m_buf[m_size - 1];
}

#include "Vector_iterator.tpp"
#include "Vector_const_iterator.tpp"
#include "Vector_reverse_iterator.tpp"
#include "Vector_const_reverse_iterator.tpp"

#endif