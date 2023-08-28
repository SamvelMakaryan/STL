#ifndef STACK_HPP_
#define STACK_HPP_

#include <deque>
#include <utility>

namespace my {

    template <typename T, typename Container = std::deque<T>>
    class Stack {
        static_assert(std::is_same_v<typename Container::value_type>,
        "my::Stack should have the same value_type as its underlying container");
    public:
        using value_type      = typename Container::value_type;
        using size_type       = typename Container::size_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using container_type  = Container;
    public:
        Stack();
        explicit Stack(const Container&);
        explicit Stack(Container&&);
        Stack(const Stack&);
        Stack(Stack&&);
        template <typename InputIt>
        Stack(InputIt, InputIt);
        template<typename Alloc>
        explicit Stack(const Alloc&);
        template<typename Alloc>
        Stack(const Container&, const Alloc&);
        template<typename Alloc>
        Stack(Container&&, const Alloc&);
        template<typename Alloc>
        Stack(const Stack&, const Alloc&);
        template<typename Alloc>
        Stack(Stack&&, const Alloc&);
        template<typename InputIt, typename Alloc>
        Stack(InputIt, InputIt, const Alloc&);
        ~Stack();
    public:
        Stack& operator=(const Stack&);
        Stack& operator=(Stack&&) noexcept;
        bool operator==(const Stack&) const;
        bool operator!=(const Stack&) const;
        bool operator<(const Stack&) const;
        bool operator>(const Stack&) const;
        bool operator<=(const Stack&) const;
        bool operator>=(const Stack&) const;
    public:
        reference top();
        const_reference top() const;
        [[nodiscard]] bool empty() const;
        size_type size() const;
        void push(const value_type&);
        void push(value_type&&);
        void pop();
        template <typename... Args>
        decltype(auto) emplace(Args&&...);
        void swap(Stack&) noexcept(std::is_nothrow_swappable_v<Container>);
    protected:
        Container m_cont;
    };

    #include "Stack.tpp"
    #include "Stack_deduction_guides.tpp"
}

#endif //STACK_HPP_
