//insert
//push_back
//assign
//emplace empalce_back
//erase
#ifndef VECTOR_BOOL_hPP_
#define VECTOR_BOOL_hPP_
#include "Vector.hpp"

template<typename Alloc>
class Vector<bool, Alloc> {
public:
	class reference;
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;
public:
	using value_type 	 		 = bool;
	using allocator_type 		 = Allocator<value_type>;
	using size_type 	 		 = size_t;	
	using difference_type 		 = std::ptrdiff_t;
	using pointer 		  		 = value_type*;
	using const_pointer   		 = const pointer;
	using reference 	  		 = Vector<bool, Alloc>::reference;
	using const_reference 		 = bool;
	using iterator 				 = Vector<bool, Alloc>::iterator;
	using const_iterator 		 = Vector<bool, Alloc>::const_iterator;
	using reverse_iterator 		 = Vector<bool, Alloc>::reverse_iterator;
	using reverse_const_iterator = Vector<bool, Alloc>::const_reverse_iterator;
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
		constexpr reference(unsigned char*, size_t);
		constexpr reference(const reference&);
	public:
		constexpr operator bool() const noexcept;
		constexpr reference& operator=(bool) noexcept;
		constexpr reference& operator=(const reference&) noexcept;
	private:
		unsigned char* byte;
		size_t offset;
	};
public:
	class iterator {
	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type 		= bool;
		using size_type 		= size_t;
		using difference_type 	= std::ptrdiff_t;
		using reference 		= Vector<bool, Alloc>::reference;
		using const_reference 	= bool;
		using pointer 			= value_type*;
		using const_pointer 	= const value_type*;
	public:
		constexpr iterator(const iterator&);
		constexpr iterator(unsigned char*);
		constexpr iterator(unsigned char*, size_t);
	public:
		constexpr iterator& operator++();	
		constexpr iterator operator++(int);
		constexpr iterator& operator--();
		constexpr iterator operator--(int);
		constexpr iterator operator+(size_t) const; 
		constexpr size_t operator-(iterator) const;
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
		unsigned char* ptr;
		size_t index;
	};
	class const_iterator {
	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type 		= bool;
		using size_type 		= size_t;
		using difference_type 	= std::ptrdiff_t;
		using reference 		= Vector<bool, Alloc>::reference;
		using const_reference 	= bool;
		using pointer 			= value_type*;
		using const_pointer 	= const value_type*;
	public:
		constexpr const_iterator(const const_iterator&);
		constexpr const_iterator(const unsigned char*);
		constexpr const_iterator(const unsigned char*, size_t);
	public:
		constexpr const_iterator& operator++();	
		constexpr const_iterator operator++(int);
		constexpr const_iterator& operator--();
		constexpr const_iterator operator--(int);
		constexpr const_iterator operator+(size_t) const;
		constexpr const_iterator operator-(size_t) const;
		constexpr size_t operator-(const_iterator) const;
		constexpr const_iterator& operator+=(size_t); 
		constexpr const_iterator& operator-=(size_t); 
		constexpr bool operator!=(const const_iterator&) const;
		constexpr bool operator==(const const_iterator&) const;
		constexpr bool operator<(const const_iterator&) const;
		constexpr bool operator>(const const_iterator&) const;
		constexpr bool operator<=(const const_iterator&) const;
		constexpr bool operator>=(const const_iterator&) const;
		constexpr const_reference operator*() const;
	private:
		const unsigned char* ptr;
		size_t index;
	};
	class reverse_iterator {
	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type 		= bool;
		using size_type 		= size_t;
		using difference_type 	= std::ptrdiff_t;
		using reference 		= Vector<bool, Alloc>::reference;
		using const_reference 	= bool;
		using pointer 			= value_type*;
		using const_pointer 	= const value_type*;
	public:
		constexpr reverse_iterator(const reverse_iterator&);
		constexpr reverse_iterator(unsigned char*);
		constexpr reverse_iterator(unsigned char*, size_t);
	public:
		constexpr reverse_iterator& operator++();	
		constexpr reverse_iterator operator++(int);
		constexpr reverse_iterator& operator--();
		constexpr reverse_iterator operator--(int);
		constexpr reverse_iterator operator+(size_t) const;
		constexpr reverse_iterator operator-(size_t) const;
		constexpr size_t operator-(reverse_iterator) const;
		constexpr reverse_iterator& operator+=(size_t); 
		constexpr reverse_iterator& operator-=(size_t); 
		constexpr bool operator!=(const reverse_iterator&) const;
		constexpr bool operator==(const reverse_iterator&) const;
		constexpr bool operator<(const reverse_iterator&) const;
		constexpr bool operator>(const reverse_iterator&) const;
		constexpr bool operator<=(const reverse_iterator&) const;
		constexpr bool operator>=(const reverse_iterator&) const;
		constexpr const_reference operator*() const;
	private:
		unsigned char* ptr;
		size_t index;
	};
	class const_reverse_iterator {
	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type 		= bool;
		using size_type 		= size_t;
		using difference_type 	= std::ptrdiff_t;
		using reference 		= Vector<bool, Alloc>::reference;
		using const_reference 	= bool;
		using pointer 			= value_type*;
		using const_pointer 	= const value_type*;
	public:
		constexpr const_reverse_iterator(const const_reverse_iterator&);
		constexpr const_reverse_iterator(const unsigned char*);
		constexpr const_reverse_iterator(const unsigned char*, size_t);
	public:
		constexpr const_reverse_iterator& operator++();	
		constexpr const_reverse_iterator operator++(int);
		constexpr const_reverse_iterator& operator--();
		constexpr const_reverse_iterator operator--(int);
		constexpr const_reverse_iterator operator+(size_t) const;
		constexpr const_reverse_iterator operator-(size_t) const;
		constexpr size_t operator-(const_reverse_iterator) const;
		constexpr const_reverse_iterator& operator+=(size_t); 
		constexpr const_reverse_iterator& operator-=(size_t); 
		constexpr bool operator!=(const const_reverse_iterator&) const;
		constexpr bool operator==(const const_reverse_iterator&) const;
		constexpr bool operator<(const const_reverse_iterator&) const;
		constexpr bool operator>(const const_reverse_iterator&) const;
		constexpr bool operator<=(const const_reverse_iterator&) const;
		constexpr bool operator>=(const const_reverse_iterator&) const;
		constexpr const_reference operator*() const;
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
	constexpr reverse_iterator rbegin() const noexcept;
	constexpr reverse_iterator rend() const noexcept;
	constexpr const_reverse_iterator crbegin() const noexcept;
	constexpr const_reverse_iterator crend() const noexcept;
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
	constexpr static void swap(reference, reference);
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
	constexpr const unsigned char* data() const noexcept;
	constexpr unsigned char* data() noexcept;
	constexpr void assign(size_t n, bool);
	// constexpr void assign(iterator first, iterator last);
	constexpr void assign(std::initializer_list<bool>);
	constexpr void push_back(bool);
	constexpr void pop_back();
	constexpr void swap(Vector<bool, Alloc>&) noexcept;
	constexpr void clear() noexcept;
	constexpr iterator insert(iterator, const bool& = bool());
	constexpr iterator insert(iterator, size_t, const bool& = bool());
	constexpr iterator insert(iterator, iterator, iterator);
	constexpr iterator insert(iterator, std::initializer_list<bool>);
	template <typename... Args>
	constexpr bool emplace_back(Args&&...);
	template <typename... Args>
	constexpr iterator emplace(iterator, Args&&...);
	constexpr void flip();
private:
	constexpr void _realloc(size_t);
private:
	Alloc m_allocator;
	size_t m_size;
	size_t m_cap;
	unsigned char* m_buf;
};

#include "Vector_bool.tpp"
#include "Reference.hpp"
#include "Vector_bool_iterator.tpp"
#include "Vector_bool_const_iterator.tpp"
#include "Vector_bool_reverse_iterator.tpp"
#include "Vector_bool_const_reverse_iterator.tpp"

#endif //VECTOR_BOOL_HPP_
