#ifndef FORWARD_LIST_HPP_
#define FORWARD_LIST_HPP_
#include <initializer_list>
#include <type_traits>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <utility>
#include <limits>
#include "Allocator.hpp"
#include "Exception.hpp"

namespace my {
    template <typename T, typename Alloc = Allocator<T>>
    class Forward_List {
    public:
        class iterator;
        class const_iterator;
    private:
        class node_base;
        class Node;
    public:
        using value_type      = T;
        using pointer         = std::allocator_traits<Alloc>::pointer;
        using const_pointer   = std::allocator_traits<Alloc>::const_pointer;
        using size_type       = size_t;
        using difference_type = ptrdiff_t;
        using reference       = value_type&;
        using const_reference = const value_type&;
        using iterator        = Forward_List<T, Alloc>::iterator;
        using const_iterator  = Forward_List<T, Alloc>::const_iterator;
        using allocator_type  = typename std::allocator_traits<Allocator<T>>::template rebind_alloc<Node>;
    public:
        class iterator {
            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type        = T;
                using size_type 		= size_t;
                using difference_type   = std::ptrdiff_t;
                using reference 		= value_type&;
                using const_reference 	= const value_type&;
                using pointer 			= value_type*;
                using const_pointer 	= const value_type*; 
            public:
                iterator(node_base*);
                iterator(const iterator&);
            public:
                iterator& operator++(); 
			    iterator operator++(int);
			    bool operator!=(const iterator&) const;
			    bool operator==(const iterator&) const;
			    bool operator<(const iterator&) const;
			    bool operator>(const iterator&) const;
			    bool operator<=(const iterator&) const;
			    bool operator>=(const iterator&) const;
			    const T& operator*() const;
			    T& operator*();
            private:
                node_base* m_ptr;
        };
        class const_iterator {
            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type        = T;
                using size_type 		= size_t;
                using difference_type   = std::ptrdiff_t;
                using reference 		= value_type&;
                using const_reference 	= const value_type&;
                using pointer 			= value_type*;
                using const_pointer 	= const value_type*; 
            public:
                const_iterator(const node_base*);
                const_iterator(const const_iterator&);
            public:
                const_iterator& operator++(); 
			    const_iterator operator++(int);
			    bool operator!=(const const_iterator&) const;
			    bool operator==(const const_iterator&) const;
			    bool operator<(const const_iterator&) const;
			    bool operator>(const const_iterator&) const;
			    bool operator<=(const const_iterator&) const;
			    bool operator>=(const const_iterator&) const;
			    const T& operator*() const;
            private:
                const node_base* m_ptr;
        };
    public:
        Forward_List();
        explicit Forward_List(const allocator_type&);    
        Forward_List(size_type, const T&, const allocator_type& = allocator_type());
        Forward_List(size_type, const allocator_type& = allocator_type());
        template <typename InputIt, typename = typename std::enable_if_t<!std::is_arithmetic_v<InputIt>>>
        Forward_List(InputIt, InputIt, const allocator_type& = allocator_type());
        Forward_List(const Forward_List&);
        Forward_List(const Forward_List&, const allocator_type&);
        Forward_List(Forward_List&&);
        Forward_List(Forward_List&&, const allocator_type&);
        Forward_List(std::initializer_list<T>, const allocator_type& = allocator_type());
        ~Forward_List();
    public:
        iterator before_begin() noexcept;
        const_iterator before_begin() const noexcept;
        const_iterator cbefore_begin() const noexcept;
        iterator begin() noexcept;
        const_iterator begin() const noexcept;
        const_iterator cbegin() const noexcept;
        iterator end() noexcept;
        const_iterator end() const noexcept;    
        const_iterator cend() const noexcept;
    public: 
        Forward_List& operator=(const Forward_List&);
        Forward_List& operator=(Forward_List&&) noexcept(std::allocator_traits<Alloc>::is_always_equal::value);
        Forward_List& operator=(std::initializer_list<T>);
    public:
        void assign(size_type, const T&);
        void assign(std::initializer_list<T>);
        template <typename InputIt, typename = std::enable_if_t<!std::is_arithmetic_v<InputIt>>>
        void assign(InputIt, InputIt);
        allocator_type get_allocator() const noexcept;
        reference front();
        const_reference front() const;
        [[nodiscard]] bool empty() const noexcept;
        size_type max_size() const noexcept;
        void clear() noexcept;
        iterator insert_after(iterator, const T&);
        iterator insert_after(iterator, T&&);
        iterator insert_after(iterator, size_type, const T&);
        template <typename... Args>
        iterator emplace_after(iterator, Args&&...);
        template <typename... Args>
        reference emplace_front(Args&&...);
        void push_front(const T&);
        void push_front(T&&);
        void pop_front();
        iterator erase_after(iterator);
        iterator erase_after(iterator, iterator);
        void resize(size_type);
        void resize(size_type, const value_type&);
        void swap(Forward_List&) noexcept(std::allocator_traits<Alloc>::is_always_equal::value);
    private:
        struct node_base {
            node_base* m_next;
        };
        struct Node : public node_base {
            T m_data;
            template <typename... Args>
            Node(Args&&... args) :
            m_data(args...) {}
        };
    private:
        node_base m_head;
        allocator_type m_allocator;
    };

    #include "Forward_List.tpp"
    #include "Iterator.tpp"
    #include "Const_iterator.tpp"
}

#endif //FORWARD_LIST_HPP_   