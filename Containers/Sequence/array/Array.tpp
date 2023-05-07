#ifndef ARRAY_TPP_
#define ARRAY_TPP_
#include "Array.hpp"

template <typename T, size_t N>
constexpr typename Array<T, N>::size_type Array<T, N>::size() const noexcept {
    return N;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::at(size_type n) {
    return const_cast<T&>(static_cast<const Array<T, N>&>(*this)[n]);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::at(size_type n) const {
    if (n >= N) {
        throw out_of_range("error : out of range");
    }
    return m_arr[n];
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::operator[](size_type n) const {
    return m_arr[n];
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::operator[](size_type n) {
    return const_cast<T&>(static_cast<const Array<T, N>&>(*this)[n]);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::front() const {
    return m_arr[0];
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::front() {
    return const_cast<T&>(static_cast<const Array<T, N>&>(*this).front());
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::back() const {
    return m_arr[N - 1];
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::back() {
    return const_cast<T&>(static_cast<const Array<T, N>&>(*this).back());
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_pointer Array<T, N>::data() const {
    return m_arr;
}

template <typename T, size_t N>
constexpr typename Array<T, N>::pointer Array<T, N>::data() {
    return const_cast<T*>(static_cast<const Array<T, N>&>(*this).data());
}

template <typename T, size_t N>
constexpr bool Array<T, N>::empty() const noexcept {
    return (begin() == end());
}

template <typename T, size_t N>
constexpr typename Array<T, N>::size_type Array<T, N>::max_size() const noexcept {
    return N;
}

template <typename T, size_t N>
constexpr void Array<T, N>::fill(const_reference val) {
    for (auto& i : m_arr) {
        i = val;
    }
}

template <typename T, size_t N>
constexpr void Array<T, N>::swap(Array& oth) noexcept(std::is_nothrow_swappable_v<reference>) {
    for (size_type i = 0; i < N; ++i) {
        std::swap(m_arr[i], oth.m_arr[i]);
    }
}

template <typename T, size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::begin() noexcept {
    return iterator(m_arr);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::begin() const noexcept {
    return const_iterator(m_arr);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::end() noexcept {
    return iterator(m_arr + N);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::end() const noexcept {
    return const_iterator(m_arr + N);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::cbegin() const noexcept {
    return const_iterator(m_arr);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::cend() const noexcept {
    return const_iterator(m_arr + N);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator Array<T, N>::rbegin() noexcept {
    return reverse_iterator(m_arr + N - 1);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::reverse_iterator Array<T, N>::rend() noexcept {
    return reverse_iterator(m_arr - 1);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_reverse_iterator Array<T, N>::crbegin() const noexcept {
    return const_reverse_iterator(m_arr + N - 1);
}

template <typename T, size_t N>
constexpr typename Array<T, N>::const_reverse_iterator Array<T, N>::crend() const noexcept {
    return const_reverse_iterator(m_arr - 1);
}


template <typename T, size_t N>
constexpr bool Array<T, N>::operator==(const Array& oth) const {
    for (size_type i = 0; i < N; ++i) {
        if (m_arr[i] != oth.m_arr[i]) {
            return false;
        }
    }
    return true;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::operator!=(const Array& oth) const {
    return !operator==(oth);
}

template <typename T, size_t N>
constexpr bool Array<T, N>::operator<(const Array& oth) const {
    for (size_type i = 0; i < N; ++i) {
        if (m_arr[i] >= oth.m_arr[i]) {
            return false;
        }
    }
    return true;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::operator>(const Array& oth) const {
    if (operator==(oth) || operator<(oth)) {
        return false;
    }
    return true;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::operator<=(const Array& oth) const {
    return !(operator>(oth));
}

template <typename T, size_t N>
constexpr bool Array<T, N>::operator>=(const Array& oth) const {
    return !operator<(oth);
}
#endif //ARRAY_TPP_