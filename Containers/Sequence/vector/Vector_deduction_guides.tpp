#ifndef VECTOR_DEDUCTION_GUIDES_TPP_
#define VECTOR_DEDUCTION_GUIDES_TPP_
#include "Vector.hpp"

template <typename InputIt, typename Allocator = Allocator<typename std::iterator_traits<InputIt>::value_type>>
Vector(InputIt, InputIt, Allocator = Allocator()) -> Vector<typename std::iterator_traits<InputIt>::value_type, Allocator>;


#endif //VECTOR_DEDUCTION_GUIDES_TPP_
