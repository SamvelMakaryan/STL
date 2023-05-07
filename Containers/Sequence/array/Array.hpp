#ifndef ARRAY_HPP_
#define ARRAY_HPP_
#include <algorithm>
#include <cstddef>
#include "Exception.hpp"

namespace my {
    template <typename T, size_t N>
    struct Array {
    public:
        class iterator;
        class const_iterator;
        class reverse_iterator;
        class const_reverse_iterator;
    public:
        using value_type = T;
        using size_type = size_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using iterator = Array<T, N>::iterator;
        using const_iterator = Array<T, N>::const_iterator;
        using reverse_iterator = Array<T, N>::reverse_iterator;
        using const_reverse_iterator = Array<T, N>::const_reverse_iterator;
    public:
        class iterator {
            using iterator_category = std::random_access_iterator_tag;
			using value_type = T;
			using size_type = size_t;
			using difference_type = std::ptrdiff_t;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;
			using const_pointer = const value_type*;
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
            T* m_ptr;
        };
        class const_iterator {
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type = T;
			using size_type = size_t;
			using difference_type = std::ptrdiff_t;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;
			using const_pointer = const value_type*;
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
			const T* m_ptr;
		};
        class reverse_iterator {
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type = T;
			using size_type = size_t;
			using difference_type = std::ptrdiff_t;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;
			using const_pointer = const value_type*;
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
			T* m_ptr;
		};	
		class const_reverse_iterator {
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type = T;
			using size_type = size_t;
			using difference_type = std::ptrdiff_t;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;
			using const_pointer = const value_type*;
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
			const T* m_ptr;
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
        constexpr size_type size() const noexcept;
        constexpr reference at(size_type);
        constexpr const_reference at(size_type) const;
        constexpr reference front();
        constexpr const_reference front() const;
        constexpr reference back();
        constexpr const_reference back() const;
        constexpr pointer data();
        constexpr const_pointer data() const;
        [[nodiscard]] constexpr bool empty() const noexcept;
        constexpr size_type max_size() const noexcept;
        constexpr void fill(const_reference);
        constexpr void swap(Array&) noexcept(std::is_nothrow_swappable_v<reference>);
    public:
        constexpr reference operator[](size_type);
        constexpr const_reference operator[](size_type) const;
        constexpr bool operator==(const Array&) const;
        constexpr bool operator!=(const Array&) const;
        constexpr bool operator<(const Array&) const;
        constexpr bool operator>(const Array&) const;
        constexpr bool operator<=(const Array&) const;
        constexpr bool operator>=(const Array&) const;
    public:
        T m_arr[N];
    };

    #include "Array.tpp"
    #include "Iterator.tpp"
    #include "Const_iterator.tpp"
    #include "Const_reverse_iterator.tpp"
    #include "Reverse_iterator.tpp"
}

#endif //ARRAY_HPP_


