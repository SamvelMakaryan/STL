#ifndef PRIORITY_QUEUE_TPP_
#define PRIORITY_QUEUE_TPP_
#include "Priority_Queue.hpp"

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>::Priority_Queue()
 : Priority_Queue(Compare(), Container()) {}

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>::Priority_Queue
(const Compare& compare)
 : Priority_Queue(compare, Container()) {}

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>::Priority_Queue
(const Compare& compare, const Container& container) 
 : m_cont(container),
   m_comp(compare) 
   {
    std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
   }

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>::Priority_Queue
(const Compare& compare, const Container&& container) 
 : m_cont(std::move(container)),
   m_comp(compare)
    {
    std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
    }

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>::Priority_Queue
(const Priority_Queue& oth)
 : m_cont(oth.m_cont),
   m_comp(oth.m_comp) {}

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>::Priority_Queue
(Priority_Queue&& oth)
 : m_cont(std::move(oth.m_cont)),
   m_comp(std::move(oth.m_comp)) {}

template <typename T, typename Container, typename Compare>
template <typename InputIt>
Priority_Queue<T, Container, Compare>::Priority_Queue
(InputIt first, InputIt last, const Compare& compare)
 : m_cont(first, last),
   m_comp(compare) 
   {
    std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
   }

template <typename T, typename Container, typename Compare>
template <typename InputIt>
Priority_Queue<T, Container, Compare>::Priority_Queue
(InputIt first, InputIt last, const Compare& compare, const Container& container)
 : m_cont(container),
   m_comp(compare)
  {
    m_cont.insert(m_cont.end(), first, last);
    std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
  }

template <typename T, typename Container, typename Compare>
template <typename InputIt>
Priority_Queue<T, Container, Compare>::Priority_Queue
(InputIt first, InputIt last, const Compare& compare, Container&& container)
 : m_cont(std::move(container)),
   m_comp(compare)
  {
    m_cont.insert(m_cont.end(), first, last);
    std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
  }

template <typename T, typename Container, typename Compare>
template <typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(const Alloc& allocator)
 : m_cont(allocator),
   m_comp(Compare()) {}

template <typename T, typename Container, typename Compare>
template <typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(const Compare& compare, const Alloc& allocator)
 : m_cont(allocator),
   m_comp(compare) {}

template <typename T, typename Container, typename Compare>
template <typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(const Compare& compare, const Container& container, const Alloc& allocator)
 : m_cont(container, allocator),
   m_comp(compare) 
   {
    std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
   }

template <typename T, typename Container, typename Compare>
template <typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(const Compare& compare, Container&& container, const Alloc& allocator)
 : m_cont(std::move(container), allocator),
   m_comp(compare) 
   {
    std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
   }

template <typename T, typename Container, typename Compare>
template <typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(const Priority_Queue& oth, const Alloc& allocator)
 : m_cont(oth.m_cont, allocator),
   m_comp(oth.m_comp) {}

template <typename T, typename Container, typename Compare>
template <typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(Priority_Queue&& oth, const Alloc& allocator)
 : m_cont(std::move(oth.m_cont), allocator),
   m_comp(oth.m_comp) {}

template <typename T, typename Container, typename Compare>
template <typename InputIt, typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(InputIt first, InputIt last, const Alloc& allocator)
 : m_cont(first, last, allocator),
   m_comp(Compare()) {}

template <typename T, typename Container, typename Compare>
template <typename InputIt, typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(InputIt first, InputIt last, const Compare& compare, const Alloc& allocator)
 : m_cont(first, last, allocator),
   m_comp(compare) 
   {
    std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
   }

template <typename T, typename Container, typename Compare>
template <typename InputIt, typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(InputIt first, InputIt last, const Compare& compare, const Container& container, const Alloc& allocator)
 : m_cont(container, allocator),
   m_comp(compare)
    {
      m_cont.inset(m_cont.end(), first, last);
      std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
    }
template <typename T, typename Container, typename Compare>
template <typename InputIt, typename Alloc>
Priority_Queue<T, Container, Compare>::Priority_Queue
(InputIt first, InputIt last, const Compare& compare, Container&& container, const Alloc& allocator)
 : m_cont(std::move(container), allocator),
   m_comp(compare)
    {
      m_cont.inset(m_cont.end(), first, last);
      std::make_heap(m_cont.begin(), m_cont.end(), m_comp);
    }

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>::~Priority_Queue() = default;

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>& Priority_Queue<T, Container, Compare>::operator=(const Priority_Queue&) = default;  

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>& Priority_Queue<T, Container, Compare>::operator=(Priority_Queue&&) noexcept = default; 

template <typename T, typename Container, typename Compare>
[[nodiscard]] bool Priority_Queue<T, Container, Compare>::empty() const {
  return m_cont.empty();
}

template <typename T, typename Container, typename Compare>
typename Priority_Queue<T, Container, Compare>::size_type Priority_Queue<T, Container, Compare>::size() const {
  return m_cont.size();
}

template <typename T, typename Container, typename Compare>
void Priority_Queue<T, Container, Compare>::swap(Priority_Queue& oth) 
noexcept(std::is_nothrow_swappable_v<Container> && std::is_nothrow_swappable_v<Compare>) {
  using std::swap;
  swap(m_cont, oth.m_cont);
  swap(m_comp, oth.m_comp);
}

template <typename T, typename Container, typename Compare>
Priority_Queue<T, Container, Compare>::const_reference Priority_Queue<T, Container, Compare>::top() const {
  return m_cont.front();
}

template <typename T, typename Container, typename Compare>
void Priority_Queue<T, Container, Compare>::push(const value_type& val) {
  m_cont.push_back(val);
  std::push_heap(m_cont.begin(), m_cont.end(), m_comp);
}

template <typename T, typename Container, typename Compare>
void Priority_Queue<T, Container, Compare>::push(value_type&& val) {
  m_cont.push_back(std::move(val));
  std::push_heap(m_cont.begin(), m_cont.end(), m_comp);
}

template <typename T, typename Container, typename Compare>
template <typename... Args>
void Priority_Queue<T, Container, Compare>::emplace(Args&&... args) {
  m_cont.emplace_back(std::forward<Args>(args)...);
  std::push_heap(m_cont.begin(), m_cont.end(), m_comp);
}

template <typename T, typename Container, typename Compare>
void Priority_Queue<T, Container, Compare>::pop() {
  std::pop_heap(m_cont.begin(), m_cont.end(), m_comp);
  m_cont.pop_back();
}
#endif //PRIORITY_QUEUE_TPP_
