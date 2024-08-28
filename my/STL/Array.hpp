#include <stdexcept>

#include "iterator.hpp"

template <class T, std::size_t N>
class Array {
   public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    constexpr Array() = default;
    constexpr Array(const Array& other) { *this = other; }
    constexpr Array(const std::initializer_list<T>& list) { *this = list; }
    constexpr ~Array() = default;
    constexpr Array& operator=(const Array& other) {
        for (size_type i = 0; i < N; ++i) m_data[i] = other[i];
        return *this;
    }
    constexpr Array& operator=(const std::initializer_list<T>& list) {
        int f = 0;
        for (const auto& val : list) {
            m_data[f++] = val;
        }
        return *this;
    }

    // 元素访问
    [[nodiscard]] constexpr reference at(size_type pos) {
        if (pos >= N or pos < 0) throw std::out_of_range("");
        return m_data[pos];
    }
    [[nodiscard]] constexpr const_reference at(size_type pos) const {
        if (pos >= N or pos < 0) throw std::out_of_range("");
        return m_data[pos];
    }
    [[nodiscard]] constexpr reference operator[](size_type pos) {
        return m_data[pos];
    }
    [[nodiscard]] constexpr const_reference operator[](size_type pos) const {
        return m_data[pos];
    }
    [[nodiscard]] constexpr reference front() { return m_data[0]; }
    [[nodiscard]] constexpr const_reference front() const { return m_data[0]; }
    [[nodiscard]] constexpr reference back() { return m_data[N - 1]; }
    [[nodiscard]] constexpr const_reference back() const {
        return m_data[N - 1];
    }
    [[nodiscard]] constexpr pointer data() noexcept { return m_data; }
    [[nodiscard]] constexpr const_pointer data() const noexcept {
        return m_data;
    }

    // 迭代器
    [[nodiscard]] constexpr iterator<T> begin() noexcept {
        return iterator(m_data);
    }
    [[nodiscard]] constexpr const_iterator<T> begin() const noexcept {
        return const_iterator(m_data);
    }
    [[nodiscard]] constexpr const_iterator<T> cbegin() const noexcept {
        return begin();
    }
    [[nodiscard]] constexpr iterator<T> end() noexcept {
        return iterator(m_data + N);
    }
    [[nodiscard]] constexpr const_iterator<T> end() const noexcept {
        return const_iterator(m_data + N);
    }
    [[nodiscard]] constexpr const_iterator<T> cend() const noexcept {
        return end();
    }
    [[nodiscard]] constexpr reverse_iterator<T> rbegin() noexcept {
        return reverse_iterator(m_data + N - 1);
    }
    [[nodiscard]] constexpr const_reverse_iterator<T> rbegin() const noexcept {
        return const_reverse_iterator(m_data + N - 1);
    }
    [[nodiscard]] constexpr const_reverse_iterator<T> crbegin() const noexcept {
        return rbegin();
    }
    [[nodiscard]] constexpr reverse_iterator<T> rend() noexcept {
        return reverse_iterator(m_data - 1);
    }
    [[nodiscard]] constexpr const_reverse_iterator<T> rend() const noexcept {
        return const_reverse_iterator(m_data - 1);
    }
    [[nodiscard]] constexpr const_reverse_iterator<T> crend() const noexcept {
        return rend();
    }

    // 容量
    [[nodiscard]] constexpr bool empty() const noexcept { return N == 0; }
    [[nodiscard]] constexpr size_type size() const noexcept { return N; }
    [[nodiscard]] constexpr size_type max_size() const noexcept { return N; }

    // 操作
    constexpr void fill(const_reference value) {
        for (auto it = begin(); it != end(); ++it) *it = value;
    }
    constexpr void swap(Array& other) noexcept {
        for (size_type i = 0; i < N; ++i) std::swap(m_data[i], other[i]);
    }

    // 比较
    constexpr bool operator==(const Array<T, N>& other) const {
        for (size_type i = 0; i < N; ++i) {
            if (m_data[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    constexpr auto operator<=>(const Array<T, N>& other) const {
        for (size_type i = 0; i < N; ++i) {
            if (m_data[i] < other[i]) return -1;
            else if (other[i] < m_data[i]) return 1;
        }
        return 0;
    }

   private:
    T m_data[N];
};

namespace std {
// get
template <std::size_t I, class T, std::size_t N>
[[nodiscard]] constexpr T& get(Array<T, N>& a) noexcept {
    static_assert(I < N, "array index is within bounds");
    return a[I];
}

template <std::size_t I, class T, std::size_t N>
[[nodiscard]] constexpr T&& get(Array<T, N>&& a) noexcept {
    static_assert(I < N, "array index is within bounds");
    return a[I];
}

template <std::size_t I, class T, std::size_t N>
[[nodiscard]] constexpr const T& get(const Array<T, N>& a) noexcept {
    static_assert(I < N, "array index is within bounds");
    return a[I];
}

template <std::size_t I, class T, std::size_t N>
[[nodiscard]] constexpr const T&& get(const Array<T, N>&& a) noexcept {
    static_assert(I < N, "array index is within bounds");
    return a[I];
}
// 交换容器
template <class T, std::size_t N>
void swap(Array<T, N>& lhs, Array<T, N>& rhs) noexcept {
    lhs.swap(rhs);
}

}  // namespace std

