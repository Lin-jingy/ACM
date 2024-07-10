#include <bits/stdc++.h>

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

    Array() = default;
    Array(const Array &other);
    ~Array() = default;
    [[nodiscard]] constexpr reference at(size_type pos);
    [[nodiscard]] constexpr const_reference at(size_type pos) const;
    [[nodiscard]] constexpr reference operator[] (size_type pos);
    [[nodiscard]] constexpr const_reference operator[] (size_type pos) const;
    [[nodiscard]] constexpr reference front();
    [[nodiscard]] constexpr const_reference front() const;
    [[nodiscard]] constexpr reference back();
    [[nodiscard]] constexpr const_reference back() const;
    [[nodiscard]] constexpr pointer data() noexcept;
    [[nodiscard]] constexpr const_pointer data() const noexcept;
    class iterator {
    public:
        iterator() = default;
        ~iterator() = default;
        iterator(T *ptr);
        iterator(const iterator &ptr);
        T& operator*() const noexcept;
        T* operator->() const noexcept;
        iterator& operator=(const iterator &ptr);
        iterator& operator++() noexcept;
        iterator operator++(int) noexcept;
        iterator& operator--() noexcept;
        iterator operator--(int) noexcept;
        iterator& operator+=(const size_t pos) noexcept;
        iterator operator+(const size_t pos) const noexcept;
        iterator& operator-=(const size_t pos) noexcept;
        iterator operator-(const size_t pos) const noexcept;
        friend bool operator==(const iterator a, const iterator b);
        friend bool operator!=(const iterator a, const iterator b);
    private:
        T *m_ptr;
    };
    class const_iterator : public iterator {
        T& operator*() const noexcept = delete;
        T* operator->() const noexcept = delete;
    };
    class reverse_iterator : public iterator {
        iterator& operator++() noexcept;
        iterator operator++(int) noexcept;
        iterator& operator--() noexcept;
        iterator operator--(int) noexcept;
        iterator& operator+=(const size_t pos) noexcept;
        iterator operator+(const size_t pos) const noexcept;
        iterator& operator-=(const size_t pos) noexcept;
        iterator operator-(const size_t pos) const noexcept;
    };
    class const_reverse_iterator : public reverse_iterator {
        T& operator*() const noexcept = delete;
        T* operator->() const noexcept = delete;
    };
    [[nodiscard]] constexpr iterator begin() noexcept;
    [[nodiscard]] constexpr const_iterator begin() const noexcept;
    [[nodiscard]] constexpr const_iterator cbegin() const noexcept;
    [[nodiscard]] constexpr iterator end() noexcept;
    [[nodiscard]] constexpr const_iterator end() const noexcept;
    [[nodiscard]] constexpr const_iterator cend() const noexcept;
    [[nodiscard]] constexpr reverse_iterator rbegin() noexcept;
    [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept;
    [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept;
    [[nodiscard]] constexpr reverse_iterator rend() noexcept;
    [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept;
    [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept;
    [[nodiscard]] constexpr bool empty() const noexcept;
    constexpr void fill(const T& value);
    constexpr void swap(Array& other) noexcept;
    constexpr bool operator== (const Array &other) const noexcept;
    constexpr auto operator<=> (const Array &other) const noexcept;
    constexpr Array& operator= (const Array &other) noexcept;
private:
    T m_data[N];
};
