#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <initializer_list>
#include <climits>
#include <exception>
#include <type_traits>
#include "Allocator.h"

namespace my {
	template <typename T, typename Alloc = Allocator<T>>
	class Vector {
		class out_of_range;
		using value_type = T;
		using allocator_type = Allocator<value_type>;
		using size_type = size_t;
		using difference_type = std::ptrdiff_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;

	public:
		constexpr Vector();
		constexpr explicit Vector(size_t);
		constexpr Vector(size_t, const T&);
		constexpr Vector(const Vector<T, Alloc> &);
		constexpr Vector(Vector<T, Alloc> &&) noexcept;
		constexpr Vector(std::initializer_list<T>);
		template <typename InputIterator, typename = typename std::enable_if_t<!std::is_arithmetic_v<InputIterator>>>
		constexpr Vector(InputIterator, InputIterator);
		constexpr ~Vector();
	public:
		class iterator {
		public:
			iterator(T* ptr) : ptr(ptr) {}
			iterator& operator++() { ++ptr; return *this;}
			iterator operator++(int) { iterator tmp = *this; ++ptr; return tmp;}
			iterator& operator--() { --ptr; return *this;}
			iterator operator--(int) { iterator tmp = *this; --ptr; return tmp;}
			iterator operator+(size_t n) const { iterator tmp = *this; tmp.ptr += n; return tmp;} 
			iterator operator-(size_t n) const { iterator tmp = *this; tmp.ptr -= n; return tmp;}
			iterator& operator+=(size_t n) {  ptr += n; return *this;} 
			iterator& operator-=(size_t n) {  ptr -= n; return *this;} 
			bool operator!=(const iterator& oth) const { return ptr != oth.ptr;}
			bool operator==(const iterator& oth) const { return ptr == oth.ptr;}
			bool operator<(const iterator& oth) const { if (ptr < oth.ptr) { return true;} return false;}
			bool operator>(const iterator& oth) const { if (ptr > oth.ptr) { return true;} return false;}
			bool operator<=(const iterator& oth) const {if (ptr <= oth.ptr) { return true;} return false;}
			bool operator>=(const iterator& oth) const { if (ptr >= oth.ptr) {return true;} return false;}
			const T& operator*() const { return *ptr;}
			T& operator*() { return *ptr;}
		private:
			T* ptr;
		};
		class const_iterator {
		public:
			const_iterator(const T* ptr) : ptr(ptr) {}
			const_iterator(const iterator& it) : ptr(&(*it)) {}
			const_iterator& operator++() { ++ptr; return *this;}
			const_iterator operator++(int) { const_iterator tmp = *this; ++ptr; return tmp;}
			const_iterator& operator--() { --ptr; return *this;}
			const_iterator operator--(int) { const_iterator tmp = *this; --ptr; return tmp;}
			const_iterator operator+(size_t n) const { const_iterator tmp = *this; tmp.ptr += n; return tmp;} 
			const_iterator operator-(size_t n) const { const_iterator tmp = *this; tmp.ptr -= n; return tmp;}
			const_iterator& operator+=(size_t n) {  ptr += n; return *this;} 
			const_iterator& operator-=(size_t n) {  ptr -= n; return *this;} 
			bool operator!=(const const_iterator& oth) const { return ptr != oth.ptr;}
			bool operator==(const const_iterator& oth) const { return ptr == oth.ptr;}
			bool operator<(const const_iterator& oth) const { if (ptr < oth.ptr) { return true;} return false;}
			bool operator>(const const_iterator& oth) const { if (ptr > oth.ptr) { return true;} return false;}
			bool operator<=(const const_iterator& oth) const {if (ptr <= oth.ptr) { return true;} return false;}
			bool operator>=(const const_iterator& oth) const { if (ptr >= oth.ptr) {return true;} return false;}
			const T& operator*() const { return *ptr;}
		private:
			const T* ptr;
		};
		class reverse_iterator {
		public:
			reverse_iterator(T* ptr) : ptr(ptr) {}
			reverse_iterator& operator++() { --ptr; return *this;}
			reverse_iterator operator++(int) { reverse_iterator tmp = *this; --ptr; return tmp;}
			reverse_iterator& operator--() { ++ptr; return *this;}
			reverse_iterator operator--(int) { reverse_iterator tmp = *this; ++ptr; return tmp;}
			reverse_iterator operator+(size_t n) const { reverse_iterator tmp = *this; tmp.ptr -= n; return tmp;} 
			reverse_iterator operator-(size_t n) const { reverse_iterator tmp = *this; tmp.ptr += n; return tmp;}
			reverse_iterator& operator+=(size_t n) {  ptr -= n; return *this;} 
			reverse_iterator& operator-=(size_t n) {  ptr += n; return *this;} 
			bool operator!=(const reverse_iterator& oth) const { return ptr != oth.ptr;}
			bool operator==(const reverse_iterator& oth) const { return ptr == oth.ptr;}
			bool operator<(const reverse_iterator& oth) const { if (ptr < oth.ptr) { return true;} return false;}
			bool operator>(const reverse_iterator& oth) const { if (ptr > oth.ptr) { return true;} return false;}
			bool operator<=(const reverse_iterator& oth) const {if (ptr <= oth.ptr) { return true;} return false;}
			bool operator>=(const reverse_iterator& oth) const { if (ptr >= oth.ptr) {return true;} return false;}
			const T& operator*() const { return *ptr;}
			T& operator*() { return *ptr;}
		private:
			T* ptr;
		};	
		class const_reverse_iterator {
		public:
			const_reverse_iterator(const T* ptr) : ptr(ptr) {}
			const_reverse_iterator(const iterator& it) : ptr(&(*it)) {}
			const_reverse_iterator& operator++() { --ptr; return *this;}
			const_reverse_iterator operator++(int) { const_reverse_iterator tmp = *this; --ptr; return tmp;}
			const_reverse_iterator& operator--() { ++ptr; return *this;}
			const_reverse_iterator operator--(int) { const_reverse_iterator tmp = *this; ++ptr; return tmp;}
			const_reverse_iterator operator+(size_t n) const { const_reverse_iterator tmp = *this; tmp.ptr -= n; return tmp;} 
			const_reverse_iterator operator-(size_t n) const { const_reverse_iterator tmp = *this; tmp.ptr += n; return tmp;}
			const_reverse_iterator& operator+=(size_t n) {  ptr -= n; return *this;} 
			const_reverse_iterator& operator-=(size_t n) {  ptr += n; return *this;} 
			bool operator!=(const const_reverse_iterator& oth) const { return ptr != oth.ptr;}
			bool operator==(const const_reverse_iterator& oth) const { return ptr == oth.ptr;}
			bool operator<(const const_reverse_iterator& oth) const { if (ptr < oth.ptr) { return true;} return false;}
			bool operator>(const const_reverse_iterator& oth) const { if (ptr > oth.ptr) { return true;} return false;}
			bool operator<=(const const_reverse_iterator& oth) const {if (ptr <= oth.ptr) { return true;} return false;}
			bool operator>=(const const_reverse_iterator& oth) const { if (ptr >= oth.ptr) {return true;} return false;}
			const T& operator*() const { return *ptr;}
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
		constexpr bool operator<(Vector<T, Alloc> & vec) const;
		constexpr bool operator>(Vector<T, Alloc> & vec) const;
		constexpr bool operator>=(Vector<T, Alloc> & vec) const;
		constexpr bool operator<=(Vector<T, Alloc> & vec) const;
		constexpr bool operator==(const Vector<T, Alloc> &) const;
		constexpr auto operator<=>(const Vector<T, Alloc> & oth) const;
		constexpr bool operator!=(const Vector<T, Alloc> &) const;
		constexpr const T& operator[](size_t) const;
		constexpr T& operator[](size_t);
	public:
		constexpr iterator erase(iterator it);
		constexpr iterator erase(iterator first, iterator last);
		constexpr iterator insert(iterator it, const T& val);
		constexpr iterator insert(iterator it, size_t n, const T& val);
		constexpr iterator insert(iterator it, iterator first, iterator last);
		constexpr iterator insert(iterator it, T&& val);
		constexpr iterator insert(iterator it, std::initializer_list<T> init);
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
		constexpr void assign(size_t n, const T&);
		constexpr void assign(iterator first, iterator last);
		constexpr void assign(std::initializer_list<T>);
		constexpr void push_back(const T&);
		constexpr void push_back(T&&);    
		constexpr void pop_back();
		constexpr void swap(Vector<T, Alloc>&) noexcept;
		constexpr void clear() noexcept;
		constexpr const T& at(size_t) const;
		constexpr T& at(size_t);
	private:
		constexpr void _realloc(size_t);
	private:
		size_t m_size;
		size_t m_cap;
		T* m_buf;
};

class out_of_range : public std::exception {
public:
	const char* what() {
		return msg;
	}
public:
	out_of_range(const char* str)
	: msg(str)
	{}
private:
	const char* msg;
};

#include "Vectorimplementation.h"
#include "VectorBools.h"
}
#endif

