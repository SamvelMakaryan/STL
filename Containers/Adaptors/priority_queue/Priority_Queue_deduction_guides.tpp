#ifndef PRIORITY_QUEUE_DEDUCTION_GUIDES_TPP_
#define PRIORITY_QUEUE_DEDUCTION_GUIDES_TPP_
#include <iterator>
#include "Priority_Queue.hpp"

template <typename Compare, typename Container>
Priority_Queue(Compare, Container) 
-> Priority_Queue<typename Container::value_type,  Container, Compare>;

template <typename InputIt,
          typename Compare = std::less<typename std::iterator_traits<InputIt>::value_type>,
          typename Container = std::vector<typename std::iterator_traits<InputIt>::value_type>>
Priority_Queue(InputIt, InputIt, Compare = Compare(), Container = Container()) 
-> Priority_Queue<typename std::iterator_traits<InputIt>::value_type>;

template <typename Compare, typename Container, typename Alloc>
Priority_Queue(Compare, Container, Alloc) 
-> Priority_Queue<typename Container::value_type, Container, Compare>;

template <typename InputIt, typename Alloc>
Priority_Queue(InputIt, InputIt, Alloc) 
-> Priority_Queue<typename std::iterator_traits<InputIt>::value_type,
                  std::vector<typename std::iterator_traits<InputIt>::value_type, Alloc>,
                  std::less<typename std::iterator_traits<InputIt>::value_type>>;

template <typename InputIt, typename Compare, typename Alloc>
Priority_Queue(InputIt, InputIt, Compare, Alloc) 
-> Priority_Queue<typename std::iterator_traits<InputIt>::value_type,
                  std::vector<typename std::iterator_traits<InputIt>::value_type, Alloc>, Compare>;

template <typename InputIt, typename Compare, typename Container, typename Alloc>
Priority_Queue(InputIt, InputIt, Compare, Container, Alloc)
->  Priority_Queue<typename Container::value_type, Container, Compare>;

#endif //PRIORITY_QUEUE_DEDUCTION_GUIDES_TPP_