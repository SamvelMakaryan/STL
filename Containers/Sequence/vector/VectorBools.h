template <> 
class Vector<bool> {
public:
	constexpr Vector();
	constexpr explicit Vector(size_t);
	constexpr Vector(size_t, bool);
	constexpr Vector(std::initializer_list<bool>);
	constexpr Vector(const Vector<bool> &);
	constexpr Vector(Vector<bool> &&) noexcept;
	constexpr ~Vector();
public:
	class reference {
	public:
		constexpr reference(unsigned char* byte, size_t offset) : byte(byte), offset(offset) {}
		constexpr reference(const reference&) = default;
		constexpr operator bool() const noexcept {
			return (*byte >> offset) & 1;
		}
		constexpr reference& operator=(bool val) noexcept {
			if (val) {
				*byte |= 1 << offset;
			} else {
				*byte &= ~(1 << offset);
			}
			return *this;
		}
		reference& operator=(const reference& rhs) noexcept {
			return operator=(static_cast<bool>(rhs));
		}
	private:
		unsigned char* byte;
		size_t offset;
	};
	class const_reference {
	public:
		constexpr const_reference(const unsigned char* byte, size_t index) : byte(byte), offset(offset) {}
		constexpr operator bool() const noexcept {
			return (*byte >> offset) & 1; 
		}
	private:
		const unsigned char* byte;
		size_t offset;
	};
public:
	class iterator {
	public:
		constexpr iterator(const iterator&) = default;
		constexpr iterator(unsigned char* ptr) : ptr(ptr), index(0) {}
		constexpr iterator(unsigned char* ptr, size_t index) : ptr(ptr), index(index) {}
		iterator& operator++() { ++index; return *this;}	
		iterator operator++(int) { iterator tmp = *this; ++index; return tmp;}
		iterator& operator--() { --index; return *this;}
		iterator operator--(int) { iterator tmp = *this; --index; return tmp;}
		iterator operator+(size_t n) const { iterator tmp = *this; tmp.index+= n; return tmp;} 
		iterator operator-(size_t n) const { iterator tmp = *this; tmp.index -= n; return tmp;}
		iterator& operator+=(size_t n) {  index += n; return *this;} 
		iterator& operator-=(size_t n) {  index -= n; return *this;} 
		bool operator!=(const iterator& oth) const { return !(operator==(oth));}
		bool operator==(const iterator& oth) const { return (ptr == oth.ptr && index == oth.index);}
		bool operator<(const iterator& oth) const { if (*(*this) < *oth) { return true;} return false;}
		bool operator>(const iterator& oth) const { return !(*this == oth || *this < oth);}
		bool operator<=(const iterator& oth) const { return !(*this > oth); }
		bool operator>=(const iterator& oth) const { return !(*this < oth);}
		const reference operator*() const { return reference(ptr, index);}
		reference operator*() { return reference(ptr, index);}
	private:
		unsigned char* ptr;
		size_t index;
	};
	class const_iterator {
	public:
		constexpr const_iterator(const const_iterator&) = default;
		constexpr const_iterator(const unsigned char* ptr) : ptr(ptr), index(0) {}
		constexpr const_iterator(const unsigned char* ptr, size_t index) : ptr(ptr), index(index) {}
		const_iterator& operator++() { ++index; return *this;}	
		const_iterator operator++(int) { const_iterator tmp = *this; ++index; return tmp;}
		const_iterator& operator--() { --index; return *this;}
		const_iterator operator--(int) { const_iterator tmp = *this; --index; return tmp;}
		const_iterator operator+(size_t n) const { const_iterator tmp = *this; tmp.index+= n; return tmp;} 
		const_iterator operator-(size_t n) const { const_iterator tmp = *this; tmp.index -= n; return tmp;}
		const_iterator& operator+=(size_t n) {  index += n; return *this;} 
		const_iterator& operator-=(size_t n) {  index -= n; return *this;} 
		bool operator!=(const const_iterator& oth) const { return !(operator==(oth));}
		bool operator==(const const_iterator& oth) const { return (ptr == oth.ptr && index == oth.index);}
		bool operator<(const const_iterator& oth) const { if (*(*this) < *oth) { return true;} return false;}
		bool operator>(const const_iterator& oth) const { return !(*this == oth || *this < oth);}
		bool operator<=(const const_iterator& oth) const { return !(*this > oth); }
		bool operator>=(const const_iterator& oth) const { return !(*this < oth);}
		const_reference operator*() const { return const_reference(ptr, index);}
	private:
		const unsigned char* ptr;
		size_t index;
	};
public:
	constexpr iterator begin() noexcept;
	constexpr const_iterator begin() const noexcept;
	constexpr iterator end() noexcept;
	constexpr const_iterator end() const noexcept;
	constexpr const_iterator cbegin() const noexcept;
	constexpr const_iterator cend() const noexcept;
public:
	constexpr Vector<bool>& operator=(const Vector &); 
	constexpr Vector<bool>& operator=(Vector &&) noexcept;
	constexpr Vector<bool>& operator=(std::initializer_list<bool>);
	constexpr reference operator[](size_t);
	constexpr const reference operator[](size_t) const;
	constexpr bool operator<(const Vector<bool> &) const;
	constexpr bool operator>=(const Vector<bool> &) const;
	constexpr bool operator<=(const Vector<bool> &) const;
	constexpr bool operator>(const Vector<bool> &) const;
	constexpr bool operator!=(const Vector<bool> &) const;
	constexpr bool operator==(const Vector<bool> &) const;
	constexpr auto operator<=>(const Vector<bool> &) const;
public:
	constexpr size_t size() const noexcept;
	constexpr size_t capacity() const noexcept;
	constexpr const reference at(size_t) const;
	constexpr reference at(size_t);
	constexpr reference front();
	constexpr const reference front() const;
	constexpr reference back();
	constexpr const reference back() const;
	[[nodiscard]] constexpr bool empty() const noexcept;
	constexpr size_t max_size() const noexcept; 
	constexpr void resize(size_t);
	constexpr void resize(size_t, bool);
	constexpr void reserve(size_t);
	constexpr void shrink_to_fit();
	constexpr const unsigned char* data() const noexcept;
	constexpr unsigned char* data() noexcept;
	constexpr void assign(size_t n, bool);
	// constexpr void assign(iterator first, iterator last);
	constexpr void assign(std::initializer_list<bool>);
	constexpr void push_back(bool);
	constexpr void pop_back();
	constexpr void swap(Vector<bool>&) noexcept;
	constexpr void clear() noexcept;
private:
	constexpr void _realloc(size_t);
private:
	size_t m_size;
	size_t m_cap;
	unsigned char* m_buf;
};

constexpr Vector<bool>::Vector() : m_size(0), m_cap(0), m_buf(nullptr) {}

constexpr Vector<bool>::Vector(size_t n) : m_size(n), m_cap(n) {
	m_buf = new unsigned char [(m_cap + 7) / 8];
}

constexpr Vector<bool>::Vector(size_t n, bool val) : m_size(n), m_cap(n) {
	m_buf = new unsigned char [(m_cap + 7) / 8];
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

constexpr Vector<bool>::Vector(std::initializer_list<bool> init) : m_size(init.size()), m_cap(m_size) {
	m_buf = new unsigned char [(m_cap + 7) / 8];
	size_t count = 0;
	for (auto& i : init) {
		size_t offset = count % 8;
		size_t byte = count / 8; 
		if (i) {
			*(m_buf + byte) |= (1 << offset);
		}
		else  {
			*(m_buf + byte) &= ~(1 << offset);
		}
		++count;
	}
}
		
constexpr Vector<bool>::Vector(const Vector<bool> & oth) : m_size(oth.m_size), m_cap(oth.m_cap) {
	m_buf = new unsigned char [(m_cap + 7) / 8];
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

constexpr Vector<bool>::Vector(Vector<bool> && oth) noexcept : m_size(oth.m_size), m_cap(oth.m_cap) {
	m_buf = oth.m++()_buf;
	oth.m_buf = nullptr;
	oth.m_size = 0;
	oth.m_cap = 0;
}

constexpr Vector<bool>::~Vector() {
	delete[] m_buf;
	m_buf = nullptr;
}


constexpr  Vector<bool>::reference Vector<bool>::operator[](size_t n) {
	return reference(m_buf + n / 8, n % 8);
}

constexpr const Vector<bool>::reference Vector<bool>::operator[](size_t n) const {
	return reference(m_buf + n / 8, n % 8);
}

constexpr size_t Vector<bool>::size() const noexcept {
	return m_size;
}

constexpr size_t Vector<bool>::capacity() const noexcept {
	return m_cap;
}

constexpr const Vector<bool>::reference Vector<bool>::at(size_t n) const {
	if (n > m_size) {
		throw out_of_range("error : out of range");
	}
	return reference(m_buf + n / 8, n % 8);
}

constexpr Vector<bool>::reference Vector<bool>::at(size_t n) {
	if (n > m_size) {
		throw out_of_range("error : out of range");
	}
	return reference(m_buf + n / 8, n % 8);
}

constexpr Vector<bool>::reference Vector<bool>::front() {
    return reference(m_buf, 0);
}

constexpr const Vector<bool>::reference Vector<bool>::front() const {
    return reference(m_buf, 0);
}

constexpr Vector<bool>::reference Vector<bool>::back() {
    return operator[](m_size - 1);
}

constexpr const Vector<bool>::reference Vector<bool>::back() const {
    return operator[](m_size - 1);
}

constexpr bool Vector<bool>::empty() const noexcept {
	return !m_size;
}

constexpr size_t Vector<bool>::max_size() const noexcept {
	return (sizeof(size_t) == 4) ? UINT_MAX  : ULONG_LONG_MAX;
}

constexpr void Vector<bool>::_realloc(size_t n) {
		m_cap = n;
		unsigned char* tmp = new unsigned char [(m_cap + 7) / 8];
		for (size_t i = 0; i < m_size; ++i) {
			tmp[i] = m_buf[i];
		}
		delete[] m_buf;
		m_buf = tmp;
		tmp = nullptr;
}

constexpr void Vector<bool>::resize(size_t n) {
	if (m_size == n) {
		return;
	}
	if (m_size > n ) {
		m_size = n;
	}
	else if (m_size < n && n < m_cap) {
		m_size = n;
	}
	else {
		_realloc(n * 2);
		m_size = n;
	}
}

constexpr void Vector<bool>::resize(size_t n, bool val) {
	if (n == m_size) {
			return;
		}
	if (n < m_size) {
		m_size = n;
	}
	else if (n > m_size && n < m_cap) {
		for (size_t i = m_size; i < n; ++i) {
			operator[](i) = val;
		}
		m_size = n;
	}
	else {
		_realloc(n * 2);
		for (size_t i = m_size; i < n; ++i) {
			operator[](i) = val;
		}
		m_size = n;
	}
}

constexpr void Vector<bool>::reserve(size_t n) {
	if (n <= m_cap) {
		return;
	}
	_realloc(n);
}

constexpr Vector<bool>& Vector<bool>::operator=(const Vector& rhs) {
	if (this == &rhs) {
		return *this;
	}
	delete[] m_buf;
	m_size = rhs.m_size;
	m_cap = rhs.m_cap;
	m_buf = new unsigned char [(m_cap + 7) / 8];
	for (int i = 0; i < m_size; ++i) {
		m_buf[i] = rhs.m_buf[i];
	}
	return *this;
}

constexpr Vector<bool>& Vector<bool>::operator=(Vector&& rhs) noexcept {
	delete[] m_buf;
	m_buf = rhs.m_buf;
	m_size = rhs.m_size;
	m_cap = rhs.m_cap;
	rhs.m_buf = nullptr;
	rhs.m_size = 0;
	rhs.m_cap = 0;
	return *this;
}

constexpr Vector<bool>& Vector<bool>::operator=(std::initializer_list<bool> init) {
	delete[] m_buf;
	m_size = init.size();
	m_cap = m_size * 2;
	m_buf = new unsigned char [(m_cap + 7) / 8];
	size_t count = 0;
	for (auto& i : init) {
		size_t byte = count / 8;
		size_t offset = count % 8;
		if (i) {
			*(m_buf + byte) |= (1 << offset);
		}
		else {
			*(m_buf + byte) &= ~(1 << offset);
		}
		++count;
	}
	return *this;
}

constexpr bool Vector<bool>::operator<(const Vector<bool>& vec) const {
	for (size_t i = 0; i < m_size; ++i) {
		if (operator[](i) < vec[i]) {
			return true;
		}
	}
	return false;
}

constexpr bool Vector<bool>::operator>=(const Vector<bool>& vec) const {
	return !(*this < vec);
}

constexpr bool Vector<bool>::operator==(const Vector<bool>& vec) const {
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

constexpr auto Vector<bool>::operator<=>(const Vector<bool>& oth) const {
	auto result = (m_buf[0] <=> oth.m_buf[0]);
	for (size_t i = 0; i < m_size || i < oth.size(); ++i) {
		if (m_buf[i] != oth.m_buf[i]) {
			return m_buf[i] <=> oth.m_buf[i];
		}
	}
	return result;
}

constexpr bool Vector<bool>::operator!=(const Vector<bool>& vec) const {
	return !(*this == vec);
}

constexpr bool Vector<bool>::operator<=(const Vector<bool>& vec) const {
	if (*this < vec || *this == vec) {
		return true;
	}	
	return false;
}

constexpr bool Vector<bool>::operator>(const Vector<bool>& vec) const {
	return !(*this <= vec);
}

constexpr void Vector<bool>::shrink_to_fit() {
	_realloc(m_size);
}

constexpr const unsigned char* Vector<bool>::data() const noexcept {
	return m_buf;
}

constexpr unsigned char* Vector<bool>::data() noexcept {
	return m_buf;
}

constexpr void Vector<bool>::assign(size_t n, bool val) {
	delete[] m_buf;
	m_size = n;
	m_cap = n;
	m_buf = new unsigned char [(m_cap + 7) / 8];
	for (int i = 0; i < m_size; ++i) {
		operator[](i) = val;
	}	
}

constexpr void Vector<bool>::assign(std::initializer_list<bool> init) {
	delete[] m_buf;
	m_size = init.size();
	m_cap = m_size;
	m_buf = new unsigned char [(m_cap + 7) / 8];
	int count = 0;
	for (auto& i : init) {
		operator[](count++) = i;
	}
}

constexpr void Vector<bool>::push_back(bool val) {
	if (m_cap == 0) {
		++m_cap;
		m_buf = new unsigned char [(m_cap + 7) / 8];
	}
	else if (m_size == m_cap) {
		_realloc(m_cap * 2);
	}
	operator[](m_size) = val;
	++m_size;
}
constexpr void Vector<bool>::pop_back() {
	if (m_size == 0) {
		throw out_of_range("error : out of range");
	}
	--m_size;
}

constexpr void Vector<bool>::swap(Vector<bool>& oth) noexcept {
	Vector<bool> tmp = std::move(oth);
	oth = std::move(*this);
	*this = std::move(tmp);
}

constexpr void Vector<bool>::clear() noexcept {
	m_size = 0;
}

constexpr Vector<bool>::iterator Vector<bool>::begin() noexcept {
	return iterator(m_buf);
}

constexpr Vector<bool>::iterator Vector<bool>::end() noexcept {
	return iterator(m_buf, m_size);
}

constexpr Vector<bool>::const_iterator Vector<bool>::begin() const noexcept {
	return const_iterator(m_buf);
}

constexpr Vector<bool>::const_iterator Vector<bool>::end() const noexcept {
	return const_iterator(m_buf, m_size);
}

constexpr Vector<bool>::const_iterator Vector<bool>::cbegin() const noexcept {
	return const_iterator(m_buf);
}
		
constexpr Vector<bool>::const_iterator Vector<bool>::cend() const noexcept {
	return const_iterator(m_buf, m_size);
}
