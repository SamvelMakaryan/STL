#ifndef FORWARD_LIST_TPP_
#define FORWARD_LIST_TPP_
#include "Forward_List.hpp"

template <typename T, typename Alloc>
Forward_List<T, Alloc>::Forward_List()
 : Forward_List(allocator_type()) {}

template <typename T, typename Alloc>
Forward_List<T, Alloc>::Forward_List(const allocator_type& alloc)
 : m_allocator(alloc),
   m_head(nullptr) {}

template <typename T, typename Alloc>
Forward_List<T, Alloc>::Forward_List(size_type n, const T& val, const allocator_type& alloc)
 : m_allocator(alloc)
 {
    if (n <= 0) {
        m_head.m_next = nullptr;
        return;
    }
    node_base* tmp = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(static_cast<Node*>(tmp), val);
    m_head.m_next = tmp;
    for (size_type i = 0; i < n - 1; ++i) {
        Node* new_node = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(new_node, val);
        tmp -> m_next = new_node;
        tmp = tmp -> m_next; 
    }
    tmp -> m_next = nullptr;
 }

template <typename T, typename Alloc>
Forward_List<T, Alloc>::Forward_List(size_type n, const allocator_type& alloc) 
 : Forward_List(n, T(), alloc) {}

template <typename T, typename Alloc>
template <typename InputIt, typename>
Forward_List<T, Alloc>::Forward_List(InputIt first, InputIt last, const allocator_type& alloc)
 : m_allocator(alloc)
 {
    size_type distance = std::distance(first, last);
    node_base* tmp = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(static_cast<Node*>(tmp), *first++);
    m_head.m_next = tmp;
    for (size_type i = 0; i < distance - 1; ++i) {
        Node* new_node = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(new_node, *first);
        tmp -> m_next = new_node;
        tmp = tmp -> m_next;
        ++first;
    }
    tmp -> m_next = nullptr;
 }

template <typename T, typename Alloc>
Forward_List<T, Alloc>::Forward_List(const Forward_List& oth) 
 : Forward_List(oth, oth.m_allocator) {}

template <typename T, typename Alloc>
Forward_List<T, Alloc>::Forward_List(const Forward_List& oth, const allocator_type& alloc)
 : m_allocator(alloc)
 {
    node_base* tmp2 = oth.m_head.m_next; 
    node_base* tmp1 = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(static_cast<Node*>(tmp1), static_cast<Node*>(tmp2) -> m_data);
    m_head.m_next = tmp1;
    tmp2 = tmp2 -> m_next;
    while (tmp2) {
        Node* new_node = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(new_node, static_cast<Node*>(tmp2) -> m_data);
        tmp1 -> m_next = new_node;
        tmp1 = tmp1 -> m_next;
        tmp2 = tmp2 -> m_next;
    }
    tmp1 -> m_next = nullptr;
 }

template <typename T, typename Alloc>
Forward_List<T, Alloc>::Forward_List(Forward_List&& oth, const allocator_type& alloc)
 : m_allocator(std::move(alloc)),
   m_head(oth.m_head)
 {
    oth.m_head.m_next = nullptr;
 }

template <typename T, typename Alloc>
Forward_List<T, Alloc>::Forward_List(Forward_List&& oth)
 : Forward_List(std::move(oth), std::move(oth.m_allocator)) {}

template <typename T, typename Alloc>
Forward_List<T, Alloc>::Forward_List(std::initializer_list<T> init, const allocator_type& alloc)
 : m_allocator(alloc)
 {
    auto it = init.begin();
    node_base* tmp = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(static_cast<Node*>(tmp), *it++);
    m_head.m_next = tmp;
    for (auto i = it; i != init.end(); ++i) {
        Node* new_node = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(new_node, *i);
        tmp -> m_next = new_node;
        tmp = tmp -> m_next;
    }
    tmp -> m_next = nullptr;
 }

template <typename T, typename Alloc>
Forward_List<T, Alloc>::~Forward_List() {
    clear();
}

template <typename T, typename Alloc>
void Forward_List<T, Alloc>::clear() noexcept {
    if (m_head.m_next) {
        node_base* tmp = m_head.m_next -> m_next;
        m_allocator.destroy(static_cast<Node*>(m_head.m_next));
        m_allocator.deallocate(static_cast<Node*>(m_head.m_next), sizeof(Node));
        while (tmp) {
            m_head.m_next = tmp;
            tmp = tmp -> m_next;
            m_allocator.destroy(static_cast<Node*>(m_head.m_next));
            m_allocator.deallocate(static_cast<Node*>(m_head.m_next), sizeof(Node));
        }
        m_head.m_next = nullptr;
    }
}

template <typename T, typename Alloc>
Forward_List<T, Alloc>& Forward_List<T, Alloc>::operator=(const Forward_List& oth) {
    if (&oth != this) {
        m_allocator = oth.m_allocator;
        clear();
        node_base* tmp1 = m_allocator.allocate(sizeof(Node));
        node_base* tmp2 = oth.m_head.m_next;
        m_allocator.construct(static_cast<Node*>(tmp1), static_cast<Node*>(tmp2) -> m_data);
        m_head.m_next = tmp1;
        tmp2 = tmp2 -> m_next;
        while (tmp2) {
            Node* new_node = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(new_node, static_cast<Node*>(tmp2) -> m_data);
            tmp1 -> m_next = new_node;
            tmp1 = tmp1 -> m_next;
            tmp2 = tmp2 -> m_next;
        }
        tmp1 -> m_next = nullptr;
    }
    return *this;
}

template <typename T, typename Alloc>
Forward_List<T, Alloc>& Forward_List<T, Alloc>::operator=(Forward_List&& oth)
noexcept(std::allocator_traits<Alloc>::is_always_equal::value) {
    m_allocator = std::move(oth.m_allocator);
    clear();
    m_head = oth.m_head;
    oth.m_head.m_next = nullptr;
    return *this;
}

template <typename T, typename Alloc>
Forward_List<T, Alloc>& Forward_List<T, Alloc>::operator=(std::initializer_list<T> init) {
    clear();
    auto it = init.begin();
    node_base* tmp = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(static_cast<Node*>(tmp), *it++);
    m_head.m_next = tmp;
    for (auto i = it; i != init.end(); ++i) {
        Node* new_node = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(new_node, *i);
        tmp -> m_next = new_node;
        tmp = tmp -> m_next;
    }
    tmp -> m_next = nullptr;
    return *this;
}

template <typename T, typename Alloc>
void Forward_List<T, Alloc>::assign(size_type n, const T& val) {
    clear();
    node_base* tmp = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(static_cast<Node*>(tmp), val);
    m_head.m_next = tmp;
    for (size_type i = 0; i < n - 1; ++i) {
        Node* new_node = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(new_node, val);
        tmp -> m_next = new_node;
        tmp = tmp -> m_next;
    }
    tmp -> m_next = nullptr;
}

template <typename T, typename Alloc>
void Forward_List<T, Alloc>::assign(std::initializer_list<T> init) {
    clear();
    node_base* tmp = m_allocator.allocate(sizeof(Node));
    auto it = init.begin();
    m_allocator.construct(static_cast<Node*>(tmp), *it++);
    m_head.m_next = tmp;
    for (auto i = it; i != init.end(); ++i) {
        Node* new_node = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(new_node, *i);
        tmp -> m_next = new_node;
        tmp = tmp -> m_next;
    }
    tmp -> m_next = nullptr;
}

template <typename T, typename Alloc>
template <typename InputIt, typename>
void Forward_List<T, Alloc>::assign(InputIt first, InputIt last) {
    clear();
    node_base* tmp = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(static_cast<Node*>(tmp), *first++);
    m_head.m_next = tmp;
    while (first != last) {
        Node* new_node = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(new_node, *first);
        tmp -> m_next = new_node;
        tmp = tmp -> m_next;
        ++first;
    }
    tmp -> m_next = nullptr;
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::allocator_type Forward_List<T, Alloc>::get_allocator() const noexcept {
    return m_allocator;
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::reference Forward_List<T, Alloc>::front() {
    return const_cast<T&>(static_cast<const Forward_List*>(this)->front());
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::const_reference Forward_List<T, Alloc>::front() const {
    return static_cast<Node*>(m_head.m_next) -> m_data;
}

template <typename T, typename Alloc>
[[nodiscard]] bool Forward_List<T, Alloc>::empty() const noexcept {
    return (m_head.m_next == nullptr);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator Forward_List<T, Alloc>::before_begin() noexcept {
    return iterator(&m_head);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::const_iterator Forward_List<T, Alloc>::cbefore_begin() const noexcept {
    return const_iterator(&m_head);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::const_iterator Forward_List<T, Alloc>::before_begin() const noexcept {
    return const_iterator(&m_head);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator Forward_List<T, Alloc>::begin() noexcept {
    return iterator(m_head.m_next);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::const_iterator Forward_List<T, Alloc>::begin() const noexcept {
    return const_iterator(m_head.m_next);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::const_iterator Forward_List<T, Alloc>::cbegin() const noexcept {
    return const_iterator(m_head);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator Forward_List<T, Alloc>::end() noexcept {
    return iterator(nullptr);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::const_iterator Forward_List<T, Alloc>::end() const noexcept {
    return const_iterator(nullptr);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::const_iterator Forward_List<T, Alloc>::cend() const noexcept {
    return const_iterator(nullptr);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::size_type Forward_List<T, Alloc>::max_size() const noexcept {
    return std::numeric_limits<difference_type>::max();
}

template <typename T, typename Alloc>
void Forward_List<T, Alloc>::push_front(const T& val) {
    Node* new_node = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(new_node, val);
    new_node -> m_next = m_head.m_next;
    m_head.m_next = new_node;
}

template <typename T, typename Alloc>
void Forward_List<T, Alloc>::push_front(T&& val) {
    Node* new_node = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(new_node, std::move(val));
    new_node -> m_next = m_head.m_next;
    m_head.m_next = new_node;
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator Forward_List<T, Alloc>::insert_after(iterator it, const T& val) {
    if (!m_head.m_next || it == before_begin()) {
        push_front(val);
        return begin();
    }
    node_base* tmp = m_head.m_next;
    size_type distance = std::distance(before_begin(), it);
    for (size_type i = 0; i < distance - 1; ++i) {
        tmp = tmp -> m_next;
    }
    Node* new_node = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(new_node, val);
    new_node -> m_next = tmp -> m_next;
    tmp -> m_next = new_node;
    return iterator(new_node);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator Forward_List<T, Alloc>::insert_after(iterator it, T&& val) {
    if (!m_head.m_next || it == before_begin()) {
        push_front(val);
        return begin();
    }
    node_base* tmp = m_head.m_next;
    size_type distance = std::distance(before_begin(), it);
    for (size_type i = 0; i < distance - 1; ++i) {
        tmp = tmp -> m_next;
    }
    Node* new_node = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(new_node, std::move(val));
    new_node -> m_next = tmp -> m_next;
    tmp -> m_next = new_node;
    return iterator(new_node);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator Forward_List<T, Alloc>::insert_after(iterator it, size_type n, const T& val) {
    if (n != 0) {
        if (!m_head.m_next || it == before_begin()) {
            for (size_type i = 0; i < n; ++i) {
                push_front(val);
            }
            return begin();
        }
        node_base* tmp = m_head.m_next;
        size_type distance = std::distance(before_begin(), it);
        for (size_type i = 0; i < distance - 1; ++i) {
            tmp = tmp -> m_next;
        }
        for (size_type i = 0; i < n; ++i) {
            Node* new_node = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(new_node, std::move(val));
            new_node -> m_next = tmp -> m_next;
            tmp -> m_next = new_node;
        }
        return iterator(tmp -> m_next);
    }
    return it;
}
        
template <typename T, typename Alloc>
template <typename... Args>
typename Forward_List<T, Alloc>::iterator Forward_List<T, Alloc>::emplace_after(iterator it, Args&&... args) {
    if (!m_head.m_next || it == before_begin()) {
        Node* new_node = m_allocator.allocate(sizeof(Node));
        m_allocator.construct(new_node, std::forward<Args>(args)...);
        new_node -> m_next = m_head.m_next;
        m_head.m_next = new_node;
        return begin();
    }
    node_base* tmp = m_head.m_next;
    size_type distance = std::distance(before_begin(), it);
    for (size_type i = 0; i < distance - 1; ++i) {
        tmp = tmp -> m_next;
    }
    Node* new_node = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(new_node, std::forward<Args>(args)...);
    new_node -> m_next = tmp -> m_next;
    tmp -> m_next = new_node;
    return iterator(new_node);
}

template <typename T, typename Alloc>
template <typename... Args>
typename Forward_List<T, Alloc>::reference Forward_List<T, Alloc>::emplace_front(Args&&... args) {
    Node* new_node = m_allocator.allocate(sizeof(Node));
    m_allocator.construct(new_node, std::forward<Args>(args)...);
    new_node -> m_next = m_head.m_next;
    m_head.m_next = new_node;
    return static_cast<Node*>(m_head.m_next) -> m_data;
}

template <typename T, typename Alloc>
void Forward_List<T, Alloc>::pop_front() {
    if (empty()) {
        return;
    }
    node_base* tmp = m_head.m_next;
    m_head.m_next = m_head.m_next -> m_next;
    m_allocator.destroy(static_cast<Node*>(tmp));
    m_allocator.deallocate(static_cast<Node*>(tmp), sizeof(Node));
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator Forward_List<T, Alloc>::erase_after(iterator it) {
    if (it == before_begin()) {
        pop_front();
        return begin();
    }
    size_type distance = std::distance(before_begin(), it);
    node_base* tmp = m_head.m_next;
    for (size_type i = 0; i < distance - 1; ++i) {
        tmp = tmp -> m_next;
    }
    Node* old_node = static_cast<Node*>(tmp -> m_next);
    tmp -> m_next = tmp -> m_next -> m_next;
    m_allocator.destroy(old_node);
    m_allocator.deallocate(old_node, sizeof(Node));
    return iterator(tmp -> m_next);
}

template <typename T, typename Alloc>
typename Forward_List<T, Alloc>::iterator Forward_List<T, Alloc>::erase_after(iterator first, iterator last) {
    size_type distance = std::distance(before_begin(), first);
    size_type dif = std::distance(first, last);
    if (distance == 0) {
        for (size_type i = 0; i < dif; ++i) {
            pop_front();
        }
        return begin();
    }
    node_base* tmp = m_head.m_next;
    for (size_type i = 0; i < distance - 1; ++i) {
        tmp = tmp -> m_next;
    }
    node_base* prev_pos = tmp;
    tmp = tmp -> m_next;
    for (size_type i = 0; i < dif - 1; ++i) {
        Node* old_node = static_cast<Node*>(tmp);
        tmp = tmp -> m_next;
        m_allocator.destroy(old_node);
        m_allocator.deallocate(old_node, sizeof(Node));
    }
    prev_pos -> m_next = tmp;
    
    return iterator(tmp);
}

template <typename T, typename Alloc>
void Forward_List<T, Alloc>::swap(Forward_List& oth)  noexcept(std::allocator_traits<Alloc>::is_always_equal::value) {
    std::swap(m_head, oth.m_head);
}

template <typename T, typename Alloc>
void Forward_List<T, Alloc>::resize(size_type n) {
    resize(n, T());
}   


template <typename T, typename Alloc>
void Forward_List<T, Alloc>::resize(size_type n, const value_type& val) {
    size_type distance = std::distance(begin(), end());
    if (n < distance) {
        auto it = begin();
        for (size_type i = 0; i < n - 1; ++i) {
            ++it;
        }
        erase_after(it, end());
    }
    else if (n > distance) {
        node_base* tmp = m_head.m_next;
        while (tmp -> m_next) {
            tmp = tmp -> m_next;
        }
        size_type dif = n - distance;
        for (size_type i = 0; i < dif; ++i) {
            Node* new_node = m_allocator.allocate(sizeof(Node));
            m_allocator.construct(new_node, val);
            tmp -> m_next = new_node;
            tmp = tmp -> m_next;
        }
        tmp -> m_next = nullptr;
    }
}

#endif //FORWARD_LIST_TPP_