#ifndef QUEUE_TPP_
#define QUEUE_TPP_
#include <deque>

namespace my {
    template <typename T, typename Container = std::deque<T>>
    class Queue {
    public:
        using value_type      = typename Container::value_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using size_type       = typename Container::size_type;
        using container_type  =          Container;
    public:
        
    protected:
        Container m_cont;
    };
}

#endif //QUEUE_TPP_