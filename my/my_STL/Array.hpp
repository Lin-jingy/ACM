#include <cstddef>
#include <initializer_list>
#include <stdexcept>

#include "reverse_iterator.hpp"
#include "stl_algobase.hpp"


namespace mystl {

template <class T, std::size_t N>
class Array {
    using iterator = T*;
    using const_iterator = const T*;
    using const_reverse_iterator = reverse_iterator<T, const T*>;
    using reverse_iterator = reverse_iterator<T, T*>;

   public:
    constexpr Array() = default;
    constexpr Array(const Array& other) { *this = other; }
    constexpr Array(const std::initializer_list<T>& list) { *this = list; }
    constexpr ~Array() = default;
    constexpr Array& operator=(const Array& other) {
        for (size_t i = 0; i < N; ++i) m_data[i] = other[i];
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
    [[nodiscard]] constexpr T& at(size_t pos) {
        if (pos >= N or pos < 0) throw std::out_of_range("");
        return m_data[pos];
    }
    [[nodiscard]] constexpr const T& at(size_t pos) const {
        if (pos >= N or pos < 0) throw std::out_of_range("");
        return m_data[pos];
    }
    [[nodiscard]] constexpr T& operator[](size_t pos) { return m_data[pos]; }
    [[nodiscard]] constexpr const T& operator[](size_t pos) const {
        return m_data[pos];
    }
    [[nodiscard]] constexpr T& front() { return m_data[0]; }
    [[nodiscard]] constexpr const T& front() const { return m_data[0]; }
    [[nodiscard]] constexpr T& back() { return m_data[N - 1]; }
    [[nodiscard]] constexpr const T& back() const { return m_data[N - 1]; }
    [[nodiscard]] constexpr T* data() noexcept { return m_data; }
    [[nodiscard]] constexpr const T* data() const noexcept { return m_data; }

    // 迭代器
    [[nodiscard]] constexpr iterator begin() noexcept { return m_data; }
    [[nodiscard]] constexpr const_iterator begin() const noexcept {
        return const_iterator(m_data);
    }
    [[nodiscard]] constexpr const_iterator cbegin() const noexcept {
        return begin();
    }
    [[nodiscard]] constexpr iterator end() noexcept { return m_data + N; }
    [[nodiscard]] constexpr const_iterator end() const noexcept {
        return const_iterator(m_data + N);
    }
    [[nodiscard]] constexpr const_iterator cend() const noexcept {
        return end();
    }
    [[nodiscard]] constexpr reverse_iterator rbegin() noexcept {
        return reverse_iterator(m_data);
    }
    [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator(m_data);
    }
    [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept {
        return rbegin();
    }
    [[nodiscard]] constexpr reverse_iterator rend() noexcept {
        return reverse_iterator(m_data + N);
    }
    [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator(m_data + N);
    }
    [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept {
        return rend();
    }

    // 容量
    [[nodiscard]] constexpr bool empty() const noexcept { return N == 0; }
    [[nodiscard]] constexpr size_t size() const noexcept { return N; }
    [[nodiscard]] constexpr size_t max_size() const noexcept { return N; }

    // 操作
    constexpr void fill(const T& value) {
        for (auto it = begin(); it != end(); ++it) *it = value;
    }
    constexpr void swap(Array& other) noexcept {
        for (size_t i = 0; i < N; ++i) mystl::swap(m_data[i], other[i]);
    }

    // 比较
    constexpr bool operator==(const Array<T, N>& other) const {
        for (size_t i = 0; i < N; ++i) {
            if (m_data[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    constexpr auto operator<=>(const Array<T, N>& other) const {
        for (size_t i = 0; i < N; ++i) {
            if (m_data[i] < other[i]) return -1;
            else if (other[i] < m_data[i]) return 1;
        }
        return 0;
    }

   private:
    T m_data[N];
};

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

}  // namespace mystl
