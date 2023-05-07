#ifndef STACK_TPP_
#define STACK_TPP_
#include "Stack.hpp"

template <typename T, typename Container>
Stack<T, Container>::Stack()
 : m_cont(Container()) {}

template <typename T, typename Container>
Stack<T, Container>::Stack(const Container& cont)
 : m_cont(cont) {}

template <typename T, typename Container>
Stack<T, Container>::Stack(Container&& cont)
 : m_cont(std::move(cont)) {}

template <typename T, typename Container>
Stack<T, Container>::Stack(const Stack& oth) 
 : m_cont(oth.m_cont) {}

template <typename T, typename Container>
Stack<T, Container>::Stack(Stack&& oth) 
 : m_cont(std::move(oth.m_cont)) {}

template <typename T, typename Container>
template <typename InputIt>
Stack<T, Container>::Stack(InputIt first, InputIt last) 
 : m_cont(first, last) {}

template <typename T, typename Container>
template<typename Alloc>
Stack<T, Container>::Stack(const Alloc& allocator) 
: m_cont(allocator) {}

template <typename T, typename Container>
template<typename Alloc>
Stack<T, Container>::Stack(const Container& cont, const Alloc& allocator) 
 : m_cont(cont, allocator) {} 

template <typename T, typename Container>
template<typename Alloc>
Stack<T, Container>::Stack(Container&& cont, const Alloc& allocator) 
 : m_cont(std::move(cont), allocator) {} 

template <typename T, typename Container>
template<typename Alloc>
Stack<T, Container>::Stack(const Stack& oth, const Alloc& allocator)
 : m_cont(oth.m_cont, allocator) {}

template <typename T, typename Container>
template<typename Alloc>
Stack<T, Container>::Stack(Stack&& oth, const Alloc& allocator)
 : m_cont(std::move(oth.m_cont), allocator) {}
 
template <typename T, typename Container>
template<typename InputIt, typename Alloc>
Stack<T, Container>::Stack(InputIt first, InputIt last, const Alloc& allocator)
 : m_cont(first, last, allocator) {}

template <typename T, typename Container>
Stack<T, Container>::~Stack() = default;

template <typename T, typename Container>
Stack<T, Container>& Stack<T, Container>::operator=(const Stack&) = default;

template <typename T, typename Container>
Stack<T, Container>& Stack<T, Container>::operator=(Stack&&) noexcept = default;

template <typename T, typename Container>
Stack<T, Container>::reference Stack<T, Container>::top() {
    return m_cont.back();
}

template <typename T, typename Container>
Stack<T, Container>::const_reference Stack<T, Container>::top() const {
    return m_cont.back();
}

template <typename T, typename Container>
[[nodiscard]] bool Stack<T, Container>::empty() const {
    return m_cont.empty();
}

template <typename T, typename Container>
typename Stack<T, Container>::size_type Stack<T, Container>::size() const {
    return m_cont.size();
}


template <typename T, typename Container>
void Stack<T, Container>::push(const value_type& val) {
    return m_cont.push_back(val);
}

template <typename T, typename Container>
void Stack<T, Container>::push(value_type&& val) {
    return m_cont.push_back(std::move(val));
}

template <typename T, typename Container>
void Stack<T, Container>::pop() {
    return m_cont.pop;
}

template <typename T, typename Container>
template <typename... Args>
decltype(auto) Stack<T, Container>::emplace(Args&&... args) {
    return m_cont.emplace_back(std::forward<Args>(args)...);
}

template <typename T, typename Container>
void Stack<T, Container>::swap(Stack& oth) noexcept(std::is_nothrow_swappable_v<Container>) {
    using std::swap;
    swap(m_cont, oth.m_cont);
}

template <typename T, typename Container>
bool Stack<T, Container>::operator==(const Stack& oth) const {
    return (m_cont == oth.m_cont);
}

template <typename T, typename Container>
bool Stack<T, Container>::operator!=(const Stack& oth) const {
    return (m_cont != oth.m_cont);
}

template <typename T, typename Container>
bool Stack<T, Container>::operator<(const Stack& oth) const {
    return (m_cont < oth.m_cont);
}

template <typename T, typename Container>
bool Stack<T, Container>::operator>(const Stack& oth) const {
    return (m_cont > oth.m_cont);
}

template <typename T, typename Container>
bool Stack<T, Container>::operator<=(const Stack& oth) const {
    return (m_cont <= oth.m_cont);
}

template <typename T, typename Container>
bool Stack<T, Container>::operator>=(const Stack& oth) const {
    return (m_cont >= oth.m_cont);
}

#endif //STACK_TPP_
