#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#include <cstddef>
#include <initializer_list>
#include <limits>
#include <type_traits>
#include <compare>
#include "Allocator.hpp"
#include "Exception.hpp"

namespace my {
	template <typename T, typename Alloc = Allocator<T>>
	class Vector {
	public:
		class iterator;
		class const_iterator;
		class reverse_iterator;
		class const_reverse_iterator;
	public:
		using value_type 			 = T;
		using allocator_type 		 = Allocator<value_type>;
		using size_type 			 = size_t;
		using difference_type 		 = std::ptrdiff_t;
		using reference 			 = value_type&;
		using const_reference 		 = const value_type&;
		using pointer 				 = value_type*;
		using const_pointer          = const value_type*;
		using iterator               = Vector<T, Alloc>::iterator;
		using const_iterator         =  Vector<T, Alloc>::const_iterator;
		using reverse_iterator       =  Vector<T, Alloc>::reverse_iterator;
		using const_reverse_iterator = Vector<T, Alloc>::const_reverse_iterator;
	public:
		constexpr Vector() noexcept(noexcept(Alloc()));
		constexpr explicit Vector(const Alloc &) noexcept;
		constexpr explicit Vector(size_type, const Alloc & = Alloc());
		constexpr Vector(size_type, const T&, const Alloc & = Alloc());
		constexpr Vector(const Vector &);
		constexpr Vector(const Vector &, const Alloc &);
		constexpr Vector(Vector &&) noexcept;
		constexpr Vector(Vector &&, const Alloc &);
		constexpr Vector(std::initializer_list<T>, const Alloc & = Alloc());
		template <typename InputIterator, typename = typename std::enable_if_t<!std::is_arithmetic_v<InputIterator>>>
		constexpr Vector(InputIterator, InputIterator, const Alloc & = Alloc());
		constexpr ~Vector();
	public:
		class iterator {
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type        = T;
			using size_type 		= size_t;
			using difference_type   = std::ptrdiff_t;
			using reference 		= value_type&;
			using const_reference 	= const value_type&;
			using pointer 			= value_type*;
			using const_pointer 	= const value_type*;
		public:
			constexpr iterator(T*);
			constexpr iterator(const iterator&);
		public:
			constexpr iterator& operator++(); 
			constexpr iterator operator++(int);
			constexpr iterator& operator--(); 
			constexpr iterator operator--(int);
			constexpr iterator operator+(size_t) const; 
			constexpr iterator operator-(size_t) const;
			constexpr size_t operator-(iterator&) const;
			constexpr iterator& operator+=(size_t); 
			constexpr iterator& operator-=(size_t); 
			constexpr bool operator!=(const iterator&) const;
			constexpr bool operator==(const iterator&) const;
			constexpr bool operator<(const iterator&) const;
			constexpr bool operator>(const iterator&) const;
			constexpr bool operator<=(const iterator&) const;
			constexpr bool operator>=(const iterator&) const;
			constexpr const T& operator*() const;
			constexpr T& operator*();
		private:
			T* ptr;
		};
		class const_iterator {
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type 		= T;
			using size_type 		= size_t;
			using difference_type 	= std::ptrdiff_t;
			using reference 		= value_type&;
			using const_reference 	= const value_type&;
			using pointer 			= value_type*;
			using const_pointer 	= const value_type*;
		public:
			constexpr const_iterator(const T*);
			constexpr const_iterator(const iterator&);
		public:
			constexpr const_iterator& operator++();
			constexpr const_iterator operator++(int);
			constexpr const_iterator& operator--();
			constexpr const_iterator operator--(int);
			constexpr const_iterator operator+(size_t) const; 
			constexpr const_iterator operator-(size_t) const;
			constexpr size_t operator-(const_iterator&) const;
			constexpr const_iterator& operator+=(size_t); 
			constexpr const_iterator& operator-=(size_t); 
			constexpr bool operator!=(const const_iterator&) const;
			constexpr bool operator==(const const_iterator&) const;
			constexpr bool operator<(const const_iterator&) const;
			constexpr bool operator>(const const_iterator&) const;
			constexpr bool operator<=(const const_iterator&) const;
			constexpr bool operator>=(const const_iterator&) const;
			constexpr const T& operator*() const;
		private:
			const T* ptr;
		};
		class reverse_iterator {
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type 		= T;
			using size_type 		= size_t;
			using difference_type 	= std::ptrdiff_t;
			using reference 		= value_type&;
			using const_reference 	= const value_type&;
			using pointer 			= value_type*;
			using const_pointer 	= const value_type*;
		public:
			constexpr reverse_iterator(T*);
		public:
			constexpr reverse_iterator& operator++();
			constexpr reverse_iterator operator++(int);
			constexpr reverse_iterator& operator--();
			constexpr reverse_iterator operator--(int);
			constexpr reverse_iterator operator+(size_t) const; 
			constexpr reverse_iterator operator-(size_t) const;
			constexpr reverse_iterator& operator+=(size_t); 
			constexpr reverse_iterator& operator-=(size_t); 
			constexpr bool operator!=(const reverse_iterator&) const;
			constexpr bool operator==(const reverse_iterator&) const;
			constexpr bool operator<(const reverse_iterator&) const;
			constexpr bool operator>(const reverse_iterator&) const;
			constexpr bool operator<=(const reverse_iterator&) const;
			constexpr bool operator>=(const reverse_iterator&) const;
			constexpr const T& operator*() const; 
			constexpr T& operator*(); 
		private:
			T* ptr;
		};	
		class const_reverse_iterator {
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type 		= T;
			using size_type 		= size_t;
			using difference_type 	= std::ptrdiff_t;
			using reference 		= value_type&;
			using const_reference 	= const value_type&;
			using pointer 			= value_type*;
			using const_pointer 	= const value_type*;
		public:
			constexpr const_reverse_iterator(const T*);
			constexpr const_reverse_iterator(const iterator&);
		public:
			constexpr const_reverse_iterator& operator++();
			constexpr const_reverse_iterator operator++(int);
			constexpr const_reverse_iterator& operator--();
			constexpr const_reverse_iterator operator--(int);
			constexpr const_reverse_iterator operator+(size_t) const; 
			constexpr const_reverse_iterator operator-(size_t) const;
			constexpr const_reverse_iterator& operator+=(size_t); 
			constexpr const_reverse_iterator& operator-=(size_t); 
			constexpr bool operator!=(const const_reverse_iterator&) const;
			constexpr bool operator==(const const_reverse_iterator&) const;
			constexpr bool operator<(const const_reverse_iterator&) const;
			constexpr bool operator>(const const_reverse_iterator&) const;
			constexpr bool operator<=(const const_reverse_iterator&) const;
			constexpr bool operator>=(const const_reverse_iterator&) const;
			constexpr const T& operator*() const;
		private:
			const T* ptr;
		};	
	public:
		constexpr iterator begin() noexcept;
		constexpr const_iterator begin() const noexcept;
		constexpr iterator end() noexcept;
		constexpr const_iterator end() const noexcept;
		constexpr const_iterator cbegin() const noexcept;
		constexpr const_iterator cend() const noexcept;
		constexpr reverse_iterator rbegin() noexcept;
		constexpr reverse_iterator rend() noexcept;
		constexpr const_reverse_iterator crbegin() const noexcept;
		constexpr const_reverse_iterator crend() const noexcept;
	public:
		constexpr Vector& operator=(const Vector &);
		constexpr Vector& operator=(Vector &&) noexcept;
		constexpr Vector& operator=(std::initializer_list<T>);
		constexpr bool operator<(Vector<T, Alloc> &) const;
		constexpr bool operator>(Vector<T, Alloc> &) const;
		constexpr bool operator>=(Vector<T, Alloc> &) const;
		constexpr bool operator<=(Vector<T, Alloc> &) const;
		constexpr bool operator==(const Vector<T, Alloc> &) const;
		constexpr auto operator<=>(const Vector<T, Alloc> &) const;
		constexpr bool operator!=(const Vector<T, Alloc> &) const;
		constexpr const T& operator[](size_t) const;
		constexpr T& operator[](size_t);
	public:
		template <typename... Args>
		constexpr iterator emplace(const_iterator, Args&&...);
		template <typename... Args>
		constexpr T& emplace_back(Args&&...);
		constexpr iterator erase(iterator);
		constexpr iterator erase(iterator, iterator);
		constexpr iterator insert(iterator, const T&);
		constexpr iterator insert(iterator, size_t, const T&);
		constexpr iterator insert(iterator, iterator, iterator);
		constexpr iterator insert(iterator, T&&);
		constexpr iterator insert(iterator, std::initializer_list<T>);
		constexpr size_t size() const noexcept;
		constexpr size_t max_size() const noexcept;
		constexpr size_t capacity() const noexcept;
		[[nodiscard]] constexpr bool empty() const noexcept;
		constexpr void resize(size_t);
		constexpr void resize(size_t, const T&);
		constexpr void reserve(size_t);
		constexpr void shrink_to_fit();
		constexpr const T& front() const;
		constexpr T& front();
		constexpr const T& back() const;
		constexpr T& back();
		constexpr const T* data() const noexcept;
		constexpr T* data() noexcept;
		constexpr void assign(size_t, const T&);
		constexpr void assign(iterator, iterator);
		constexpr void assign(std::initializer_list<T>);
		constexpr void push_back(const T&);
		constexpr void push_back(T&&);    
		constexpr void pop_back();
		constexpr void swap(Vector<T, Alloc>&) noexcept;
		constexpr void clear() noexcept;
		constexpr const T& at(size_t) const;
		constexpr T& at(size_t);
		constexpr allocator_type get_allocator() const noexcept;
	private:
		constexpr void _realloc(size_t);
	private:
		Alloc m_allocator;
		size_t m_size;
		size_t m_cap;
		T* m_buf;
	};
	#include "Vector.tpp"
	#include "Vector_bool.hpp"
	#include "Vector_deduction_guides.tpp"
}

#endif //VECTOR_HPP_
