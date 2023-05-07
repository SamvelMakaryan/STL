#ifndef STACK_DEDUCTION_GUIDES_TPP_
#define STACK_DEDUCTION_GUIDES_TPP_
#include "Stack.hpp"

template <typename Container>
Stack(Container) -> Stack<typename Container::value_type, Container>;

template <typename InputIt>
Stack(InputIt, InputIt) -> Stack<typename InputIt::value_type>;

template <typename Container, typename Alloc>
Stack(Container, Alloc) -> Stack<typename Container::value_type, Container>;

template <typename InputIt, typename Alloc>
Stack(InputIt, InputIt, Alloc) -> Stack<typename InputIt::value_type>;

#endif //STACK_DEDUCTION_GUIDES_TPP_
