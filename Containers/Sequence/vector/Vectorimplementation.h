template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector() : m_size(0), m_cap(0), m_buf(nullptr) {}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(size_t n) : m_size(n), m_cap(n) {
	m_buf = new T [m_cap];
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(size_t n, const T& val) : m_size(n), m_cap(n) {
	m_buf = new T [m_cap];
	for (size_t i = 0; i < m_size; ++i) {
		m_buf[i] = val;
	}
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(const Vector<T, Alloc> & vec) : m_size(vec.m_size), m_cap(vec.m_cap) {
	m_buf = new T [m_cap];
	for (size_t i = 0; i < m_size; ++i) {
		m_buf[i] = vec.m_buf[i];
	}
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(Vector<T, Alloc> && vec) noexcept : m_size(vec.m_size), m_cap(vec.m_cap) {
	m_buf = vec.m_buf;
	vec.m_buf = nullptr;
	vec.m_size = 0;
	vec.m_cap = 0;
}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::Vector(std::initializer_list<T> init) : m_size(init.size()), m_cap(m_size) {
	m_buf = new T [m_cap];
	size_t count = 0;
	for (auto& i : init) {
		m_buf[count++] = i;
	}
}

template <typename T, typename Alloc>
template <typename InputIterator, typename>
constexpr Vector<T, Alloc>::Vector(InputIterator first, InputIterator last) {
	size_t count = 0;
	size_t j = 0;
	for (auto i = first; i != last; ++i) {
		++count;
	}
	m_cap = count;
	m_size = count;
	m_buf = new T [m_cap];
	for (auto i = first ; i != last; ++i) {
		m_buf[j++] = *i;
	}
}
		
template <typename T, typename Alloc>
constexpr Vector<T, Alloc>::~Vector() { delete[] m_buf; m_buf = nullptr;}

template <typename T, typename Alloc>
constexpr Vector<T, Alloc>& Vector<T, Alloc>::operator=(const Vector & rhs) {
	if (this == &rhs) {
		return *this;
	}
	delete[] m_buf;
	m_size = rhs.m_size;
	m_cap = rhs.m_cap;
	m_buf = new T [m_cap];
	for(size_t i = 0; i < m_size; ++i) {
		m_buf[i] = rhs.m_buf[i];
	}
	return *this;
}


template <typename T, typename Alloc>
constexpr Vector<T, Alloc>& Vector<T, Alloc>::operator=(Vector && rhs) noexcept {
	delete[] m_buf;
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
	delete[] m_buf;
	m_size = init.size();
	m_cap = m_size * 2;
	m_buf = new T [m_cap];
	size_t count = 0;
	for(auto& i : init) {
		m_buf[count++] = i;
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
	return (sizeof(size_t) == 4) ? UINT_MAX / sizeof(T) : ULONG_LONG_MAX / sizeof(T);
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
		m_size = n;
	}
	else if (n > m_size && n < m_cap) {
		m_size = n;
	}
	else {
		_realloc(n * 2);
		m_size = n;
	}
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::resize(size_t n, const T& val) {
	if (n == m_size) {
		return;
	}
	if (n < m_size) {
		m_size = n;
	}
	else if (n > m_size && n < m_cap) {
		for (size_t i = m_size; i < n; ++i) {
			m_buf[i] = val;
		}
		m_size = n;
	}
	else {
		_realloc(n * 2);
		for (size_t i = m_size; i < n; ++i) {
			m_buf[i] = val;
		}
		m_size = n;
	}
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

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::assign(size_t n, const T& val) {
	delete[] m_buf;
	m_size = n;
	m_cap = n;
	m_buf = new T [m_cap];
	for (size_t i = 0; i < m_size; ++i) {
		m_buf[i] = val;
	}
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::assign(std::initializer_list<T> init) {
	delete[] m_buf;
	m_size = init.size();
	m_cap = m_size;
	m_buf = new T [m_cap];
	size_t count = 0;
	for (auto& i : init) {
		m_buf[count++] = i;
	}
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::push_back(const T& val) {
	if (m_cap == 0) {
		++m_cap;
		m_buf = new T [m_cap];
	}
	else if (m_size == m_cap) {
		_realloc(m_cap * 2);
	}
	m_buf[m_size] = val;
	++m_size;
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::push_back(T&& val) {
	if (m_cap == 0) {
		++m_cap;
		m_buf = new T [m_cap];
	}
	else if (m_size == m_cap) {
		_realloc(m_cap * 2);
	}
	m_buf[m_size] = std::move(val);
	++m_size;
}

template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::pop_back() {
	if (m_size == 0) {
		throw out_of_range("error : vector is empty");
	}
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
	m_cap = n;
	T* tmp = new T [m_cap];
	for (size_t i = 0; i < m_size; ++i) {
		tmp[i] = m_buf[i];
	}
	delete[] m_buf;
	m_buf = tmp;
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
	if (it >= end() || it < begin()) {
		throw out_of_range("error : out of range");
	}
	T* tmp = new T [m_size - 1];
	size_t j = 0; 
	for (auto i = begin(); i != it; ++i) {
			tmp[j++] = *i;
	}
	size_t it_ind = j;
	for (auto i = it + 1; i != end(); ++i) {
			tmp[j++] = *i;
	}
	delete[] m_buf;
	m_buf = tmp;
	--m_size;
	return iterator(m_buf + it_ind);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(iterator first, iterator last) {
	if(first > last || first < begin() || last >= end() || first >= end() || last < begin()) {
		throw out_of_range("error : out of range");
	}
	T* tmp = new T [m_size - 1];
	size_t j = 0; 
	for (auto i = begin(); i != first; ++i) {
		tmp[j++] = *i;
	}
	size_t it_ind = j;
	for (auto i = last; i != end(); ++i) {
		tmp[j++] = *i;
	}
	delete[] m_buf;
	m_buf = tmp;
	m_size = j;
	return iterator(m_buf + it_ind);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, const T& val) {
	if(it < begin() || it >= end()) {
		throw out_of_range("error : out of range");
	}
	m_cap *= 2;
	T* tmp = new T [m_cap];
	size_t j = 0;
	for (auto i = begin(); i != it; ++i) {
		tmp[j++] = *i;
	}
	size_t it_ind = j;
	tmp[j++] = val;
	for (auto i = it; i != end(); ++i) {
		tmp[j++] = *i;
	}
	delete[] m_buf;
	m_buf = tmp;
	m_size = j;
	return iterator(m_buf + it_ind);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, size_t n, const T& val) {
	if(it < begin() || it >= end()) {
		throw out_of_range("error : out of range");
	}
	m_cap = (m_size + n) * 2;
	T* tmp = new T [m_cap];
	size_t j = 0;
	for (auto i = begin(); i != it; ++i) {
		tmp[j++] = *i;
	}
	size_t it_ind = j;
	for (size_t i = 0; i < n; ++i) {
		tmp[j++] = val;
	}
	for (auto i = it; i != end(); ++i) {
		tmp[j++] = *i;
	}
	delete[] m_buf;
	m_buf = tmp;
	m_size += n;
	return iterator(m_buf + it_ind);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, iterator first, iterator last) {
	if(first > last || first < begin() || last >= end() || first >= end() || last < begin() || it >= end() || it < begin()) {
		throw out_of_range("error : out of range");
	}
	size_t size = 0;
	for (auto i = first; i != last; ++i) {
		++size;
	}
	m_cap = (m_size + size) * 2;
	T* tmp = new T [m_cap];
	size_t j = 0;
	for (auto i = begin(); i != it; ++i) {
		tmp[j++] = *i;
	}
	size_t it_ind = j;
	for (auto i = first; i != last; ++i) {
		tmp[j++] = *i;
	}
	for (auto i = it; i != end(); ++i) {
		tmp[j++] = *i;
	}
	delete[] m_buf;
	m_buf = tmp;
	m_size += size;
	return iterator(m_buf + it_ind);
}

template <typename T, typename Alloc>	
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, T&& val) {
	if(it < begin() || it >= end()) {
		throw out_of_range("error : out of range");
	}
	m_cap *= 2;
	T* tmp = new T [m_cap];
	size_t j = 0;
	for (auto i = begin(); i != it; ++i) {
		tmp[j++] = *i;
	}
	size_t it_ind = j;
	tmp[j++] = std::move(val);
	for (auto i = it; i != end(); ++i) {
		tmp[j++] = *i;
	}
	delete[] m_buf;
	m_buf = tmp;
	++m_size;
	return iterator(m_buf + it_ind);
}

template <typename T, typename Alloc>
constexpr typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(iterator it, std::initializer_list<T> init) {
	if(it < begin() || it >= end()) {
		throw out_of_range("error : out of range");
	}
	m_size += init.size();
	m_cap = m_size * 2;
	T* tmp = new T [m_cap];
	size_t j = 0;
	for (auto i = begin(); i != it; ++i) {
		tmp[j++] = *i;
	}
	size_t it_ind = j;
	for (auto& i : init) {
		tmp[j++] = i;
	}
	for (auto i = it; i != end(); ++i) {
		tmp[j++] = *i;
	}
	delete[] m_buf;
	m_buf = tmp;
	return iterator(m_buf + it_ind);
}
	
template <typename T, typename Alloc>
constexpr void Vector<T, Alloc>::assign(iterator first, iterator last) {
	delete[] m_buf;
	size_t size = 0;
	for (auto i = first; i != last; ++i) {
		++size;
	}
	m_size = size;
	m_cap = m_size;
	m_buf = new T [m_cap];
	size_t j = 0;
	for (auto i = first; i != last; ++i) {
		m_buf[j++] = *i;
	}
}
