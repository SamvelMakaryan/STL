//insert
//push_back
//assign
//const_iter
//reve_it
//const_rev_it
//rend rbegin
//crend cbegin
//emplace empalce_back
//erase
//flip
//swap reference

#ifndef VECTOR_BOOL_TPP
#define VECTOR_BOOL_TPP
#include "Vector.hpp"

template<typename Alloc>
class Vector<bool, Alloc> {
public:
	class reference;
	class iterator;
public:
	using value_type = bool;
	using allocator_type = Allocator<value_type>;
	using size_type = size_t;	
	using difference_type = std::ptrdiff_t;
	using pointer = value_type*;
	using const_pointer = const pointer;
	using reference = Vector<bool, Alloc>::reference;
	using const_reference = bool;
	using iterator = Vector<bool, Alloc>::iterator;
public:
	constexpr Vector() noexcept(noexcept(Alloc()));
	constexpr explicit Vector(const Alloc &) noexcept;
	constexpr explicit Vector(size_type, const Alloc & = Allocator<value_type>());
	constexpr Vector(size_type, bool, const Alloc & = Allocator<value_type>());
	constexpr Vector(std::initializer_list<bool>, const Alloc & = Allocator<value_type>());
	constexpr Vector(const Vector<bool, Alloc> &);
	constexpr Vector(const Vector<bool, Alloc> &, const Alloc &);
	constexpr Vector(Vector<bool, Alloc> &&, const Alloc &);
	constexpr Vector(Vector<bool, Alloc> &&) noexcept;
	template <typename InputIterator, typename = typename std::enable_if_t<!std::is_arithmetic_v<InputIterator>>>
	constexpr Vector(InputIterator, InputIterator, const Alloc & = Allocator<value_type>());
	constexpr ~Vector();
public:
	class reference {
	friend class Vector<bool, Alloc>;
	public:
		constexpr reference(bool*, size_t);
		constexpr reference(const reference&);
		constexpr operator bool() const noexcept;
		constexpr reference& operator=(bool) noexcept;
		constexpr reference& operator=(const reference&) noexcept;
	private:
		bool* byte;
		size_t offset;
	};
public:
	class iterator {
	public:
		constexpr iterator(const iterator&);
		constexpr iterator(bool*);
		constexpr iterator(bool*, size_t);
		constexpr iterator& operator++();	
		constexpr iterator operator++(int);
		constexpr iterator& operator--();
		constexpr iterator operator--(int);
		constexpr iterator operator+(size_t) const; 
		constexpr iterator operator-(size_t) const;
		constexpr iterator& operator+=(size_t); 
		constexpr iterator& operator-=(size_t); 
		constexpr bool operator!=(const iterator&) const;
		constexpr bool operator==(const iterator&) const;
		constexpr bool operator<(const iterator&) const;
		constexpr bool operator>(const iterator&) const;
		constexpr bool operator<=(const iterator&) const;
		constexpr bool operator>=(const iterator&) const; 
		constexpr const_reference operator*() const;
		constexpr reference operator*();
	private:
		bool* ptr;
		size_t index;
	};
	class const_iterator {
	public:
		constexpr const_iterator(const const_iterator&) = default;
		constexpr const_iterator(const bool* ptr) : ptr(ptr), index(0) {}
		constexpr const_iterator(const bool* ptr, size_t index) : ptr(ptr), index(index) {}
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
		const_reference operator*() const { return reference(ptr, index);}
	private:
		const bool* ptr;
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
	constexpr Vector<bool, Alloc>& operator=(const Vector &); 
	constexpr Vector<bool, Alloc>& operator=(Vector &&) noexcept;
	constexpr Vector<bool, Alloc>& operator=(std::initializer_list<bool>);
	constexpr reference operator[](size_t);
	constexpr const reference operator[](size_t) const;
	constexpr bool operator<(const Vector<bool, Alloc> &) const;
	constexpr bool operator>=(const Vector<bool, Alloc> &) const;
	constexpr bool operator<=(const Vector<bool, Alloc> &) const;
	constexpr bool operator>(const Vector<bool, Alloc> &) const;
	constexpr bool operator!=(const Vector<bool, Alloc> &) const;
	constexpr bool operator==(const Vector<bool, Alloc> &) const;
	constexpr auto operator<=>(const Vector<bool, Alloc> &) const;
public:
	constexpr size_t size() const noexcept;
	constexpr size_t capacity() const noexcept;
	constexpr allocator_type get_allocator() const noexcept;
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
	constexpr const bool* data() const noexcept;
	constexpr bool* data() noexcept;
	constexpr void assign(size_t n, bool);
	// constexpr void assign(iterator first, iterator last);
	constexpr void assign(std::initializer_list<bool>);
	constexpr void push_back(bool);
	constexpr void pop_back();
	constexpr void swap(Vector<bool, Alloc>&) noexcept;
	constexpr void clear() noexcept;
private:
	constexpr void _realloc(size_t);
private:
	Alloc m_allocator;
	size_t m_size;
	size_t m_cap;
	bool* m_buf;
};

#include "Vector_bool.tpp"
#include "Reference.hpp"
#include "Vector_bool_iterator.tpp"

#endif
