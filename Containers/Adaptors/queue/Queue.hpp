#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <utility>
#include <deque>

namespace my {

    template <typename T, typename Container = std::deque<T>>
    class Queue {
        static_assert(std::is_same_v<typename Container::value_type>,
        "my::Queue should have the same value_type as its underlying container");
    public:
        using value_type      = typename Container::value_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using size_type       = typename Container::size_type;
        using container_type  =          Container;
    public:
        Queue();
        Queue(Queue&&);
        Queue(const Queue&);
        explicit Queue(const Container&);
        explicit Queue(Container&&);
        template<class InputIt>
        Queue(InputIt, InputIt);
        template<class Alloc>
        explicit Queue(const Alloc&);
        template<class Alloc>
        Queue(const Container&, const Alloc&);
        template<class Alloc>
        Queue(Container&&, const Alloc&);
        template<class Alloc>
        Queue(const Queue&, const Alloc&);
        template<class Alloc>
        Queue(Queue&&, const Alloc&);
        template<class InputIt, class Alloc>
        Queue(InputIt, InputIt, const Alloc&);
        ~Queue();
    public:
        Queue& operator=(const Queue&);    
        Queue& operator=(Queue&&) noexcept;
        bool operator==(const Queue&) const;
        bool operator!=(const Queue&) const;
        bool operator<(const Queue&) const;
        bool operator>(const Queue&) const;
        bool operator<=(const Queue&) const;
        bool operator>=(const Queue&) const;
    public:
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;    
        [[nodiscard]] bool empty() const;
        size_type size() const;
        void push(const value_type&);
        void push(value_type&&);
        void pop();
        void swap(Queue&) noexcept(std::is_nothrow_swappable_v<Container>);
        template <typename... Args>
        decltype(auto) emplace(Args&&... args);
    protected:
        Container m_cont;
    };

    #include "Queue.tpp"
    #include "Queue_deduction_guides.tpp"
}

#endif //QUEUE_HPP_
