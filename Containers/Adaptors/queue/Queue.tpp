#ifndef QUEUE_TPP_
#define QUEUE_TPP_
#include "Queue.hpp"

template <typename T, typename Container>
Queue<T, Container>::Queue()
 : m_cont(Container()) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(const Container& cont)
 : m_cont(cont) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(Container&& cont)
 : m_cont(std::move(cont)) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(const Queue& oth) 
 : m_cont(oth.m_cont) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(Queue&& oth) 
 : m_cont(std::move(oth.m_cont)) {}

template <typename T, typename Container>
template <typename InputIt>
Queue<T, Container>::Queue(InputIt first, InputIt last) 
 : m_cont(first, last) {}

template <typename T, typename Container>
template<typename Alloc>
Queue<T, Container>::Queue(const Alloc& allocator) 
: m_cont(allocator) {}

template <typename T, typename Container>
template<typename Alloc>
Queue<T, Container>::Queue(const Container& cont, const Alloc& allocator) 
 : m_cont(cont, allocator) {} 

template <typename T, typename Container>
template<typename Alloc>
Queue<T, Container>::Queue(Container&& cont, const Alloc& allocator) 
 : m_cont(std::move(cont), allocator) {} 

template <typename T, typename Container>
template<typename Alloc>
Queue<T, Container>::Queue(const Queue& oth, const Alloc& allocator)
 : m_cont(oth.m_cont, allocator) {}

template <typename T, typename Container>
template<typename Alloc>
Queue<T, Container>::Queue(Queue&& oth, const Alloc& allocator)
 : m_cont(std::move(oth.m_cont), allocator) {}
 
template <typename T, typename Container>
template<typename InputIt, typename Alloc>
Queue<T, Container>::Queue(InputIt first, InputIt last, const Alloc& allocator)
 : m_cont(first, last, allocator) {}

template <typename T, typename Container>
Queue<T, Container>::~Queue() = default;

template <typename T, typename Container>
Queue<T, Container>& Queue<T, Container>::operator=(const Queue&) = default;

template <typename T, typename Container>
Queue<T, Container>& Queue<T, Container>::operator=(Queue&&) noexcept = default;

template <typename T, typename Container>
typename Queue<T, Container>::reference Queue<T, Container>::front() {
    return m_cont.front();
}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::front() const {
    return m_cont.front();
}

template <typename T, typename Container>
typename Queue<T, Container>::reference Queue<T, Container>::back() {
    return m_cont.back();
}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::back() const {
    return m_cont.back();
}

template <typename T, typename Container>
[[nodiscard]]bool Queue<T, Container>::empty() const {
    return m_cont.empty();
}

template <typename T, typename Container>
typename Queue<T, Container>::size_type Queue<T, Container>::size() const {
    return m_cont.size();
}

template <typename T, typename Container>
void Queue<T, Container>::push(const value_type& val) {
    return m_cont.push_back(val);
}

template <typename T, typename Container>
void Queue<T, Container>::push(value_type&& val) {
    return m_cont.push_back(std::move(val));
}

template <typename T, typename Container>
void Queue<T, Container>::pop() {
    return m_cont.pop_front();
}

template <typename T, typename Container>
void Queue<T, Container>::swap(Queue& oth) noexcept(std::is_nothrow_swappable_v<Container>) {
    using std::swap;
    swap(m_cont, oth.m_cont);
}

template <typename T, typename Container>
template <typename... Args>
decltype(auto) Queue<T, Container>::emplace(Args&&... args) {
    return m_cont.emplace_back(std::forward<Args>(args)...);
}

template <typename T, typename Container>
bool Queue<T, Container>::operator==(const Queue& oth) const {
    return (m_cont == oth.m_cont);
}

template <typename T, typename Container>
bool Queue<T, Container>::operator!=(const Queue& oth) const {
    return (m_cont != oth.m_cont);
}

template <typename T, typename Container>
bool Queue<T, Container>::operator<(const Queue& oth) const {
    return (m_cont < oth.m_cont);
}

template <typename T, typename Container>
bool Queue<T, Container>::operator>(const Queue& oth) const {
    return (m_cont > oth.m_cont);
}

template <typename T, typename Container>
bool Queue<T, Container>::operator<=(const Queue& oth) const {
    return (m_cont <= oth.m_cont);
}

template <typename T, typename Container>
bool Queue<T, Container>::operator>=(const Queue& oth) const {
    return (m_cont >= oth.m_cont);
}

#endif //QUEUE_TPP_