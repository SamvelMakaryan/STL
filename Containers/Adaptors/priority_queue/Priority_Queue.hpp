#ifndef PRIORITY_QUEUE_HPP_
#define PRIORITY_QUEUE_HPP_
#include <functional>
#include <algorithm>
#include <utility>
#include <vector>

namespace my {
    template <typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
    class Priority_Queue {
    public:
        using value_type      = typename Container::value_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using size_type       = typename Container::size_type;
        using container_type  = Container;
        using value_compare   = Compare;
    public:
        Priority_Queue();
        explicit Priority_Queue(const Compare&);
        Priority_Queue(const Compare&, const Container&);
        Priority_Queue(const Compare&, const Container&&);
        Priority_Queue(const Priority_Queue&);
        Priority_Queue(Priority_Queue&&);
        template <typename InputIt>
        Priority_Queue(InputIt, InputIt, const Compare& = Compare());
        template <typename InputIt>
        Priority_Queue(InputIt, InputIt, const Compare&, const Container&);
        template <typename InputIt>
        Priority_Queue(InputIt, InputIt, const Compare&, Container&&);
        template <typename Alloc>
        Priority_Queue(const Alloc&);
        template <typename Alloc>
        Priority_Queue(const Compare&, const Alloc&);
        template <typename Alloc>
        Priority_Queue(const Compare&, const Container&, const Alloc&);
        template <typename Alloc>
        Priority_Queue(const Compare&, Container&&, const Alloc&);
        template <typename Alloc>
        Priority_Queue(const Priority_Queue&, const Alloc&);
        template <typename Alloc>
        Priority_Queue(Priority_Queue&&, const Alloc&);
        template <typename InputIt, typename Alloc>
        Priority_Queue(InputIt, InputIt, const Alloc&);
        template <typename InputIt, typename Alloc>
        Priority_Queue(InputIt, InputIt, const Compare&, const Alloc&);
        template <typename InputIt, typename Alloc>
        Priority_Queue(InputIt, InputIt, const Compare&, const Container&, const Alloc&);
        template <typename InputIt, typename Alloc>
        Priority_Queue(InputIt, InputIt, const Compare&, Container&&, const Alloc&);
        ~Priority_Queue();
    public:
        Priority_Queue& operator=(const Priority_Queue&);  
        Priority_Queue& operator=(Priority_Queue&&) noexcept; 
    public:
        [[nodiscard]] bool empty() const;
        size_type size() const;
        const_reference top() const;
        void swap(Priority_Queue&) noexcept(std::is_nothrow_swappable_v<Container>
                                         && std::is_nothrow_swappable_v<Compare>);
        void push(const value_type&);
        void push(value_type&&);
        void pop();
        template <typename... Args>
        void emplace(Args&&...);
    protected:
        Container m_cont;
        Compare m_comp;
    };

    #include "Priority_Queue.tpp"
    #include "Priority_Queue_deduction_guides.tpp"
}

#endif //PRIORITY_QUEUE_HPP_