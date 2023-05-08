#ifndef QUEUE_DEDUCTION_GUIDES_TPP_
#define QUEUE_DEDUCTION_GUIDES_TPP_
#include "Queue.hpp"

template <typename Container>
Queue(Container) -> Queue<typename Container::value_type, Container>;

template <typename InputIt>
Queue(InputIt, InputIt) -> Queue<typename std::iterator_traits<InputIt>::value_type>; 

template <typename InputIt, typename Allocator>
Queue(InputIt, InputIt, Allocator) -> Queue<typename std::iterator_traits<InputIt>::value_type>; 

template <typename Container, typename Allocator>
Queue(Container, Allocator) -> Queue<typename Container::value_type, Container>;

#endif //QUEUE_DEDUCTION_GUIDES_TPP_