#include <corecrt.h>

template <class T>
class iterator {
   public:
    iterator() = default;
    iterator(T* p) : m_ptr(p) {}
    iterator(const iterator& other) : m_ptr(other.m_ptr) {}
    iterator& operator=(const iterator& ptr) = default;
    ~iterator() = default;
    T& operator*() const noexcept { return *m_ptr; }
    T* operator->() const noexcept { return m_ptr; }
    iterator& operator++() noexcept {
        ++m_ptr;
        return *this;
    }
    iterator operator++(int) noexcept {
        iterator mid(*this);
        ++m_ptr;
        return mid;
    }
    iterator& operator--() noexcept {
        --m_ptr;
        return *this;
    }
    iterator operator--(int) noexcept {
        iterator mid(*this);
        --m_ptr;
        return mid;
    }
    iterator& operator+=(const size_t pos) noexcept {
        m_ptr += pos;
        return *this;
    }
    iterator operator+(const size_t pos) const noexcept {
        iterator mid(*this);
        m_ptr += pos;
        return mid;
    }
    iterator& operator-=(const size_t pos) noexcept {
        m_ptr -= pos;
        return *this;
    }
    iterator operator-(const size_t pos) const noexcept {
        iterator mid(*this);
        m_ptr -= pos;
        return mid;
    }
    size_t operator-(const iterator other) const { return m_ptr - other.m_ptr; }
    bool operator==(const iterator& other) const {
        return m_ptr == other.m_ptr;
    }
    bool operator!=(const iterator& other) const {
        return m_ptr != other.m_ptr;
    }

   protected:
    T* m_ptr;
};

template <class T>
class const_iterator : public iterator<T> {
   public:
    const_iterator() = default;
    const_iterator(T* p) : iterator<T>(p) {}
    const_iterator(const const_iterator& other) : iterator<T>(other.m_ptr) {}
    T& operator*() const noexcept = delete;
    T* operator->() const noexcept = delete;
};

template <class T>
class reverse_iterator : public iterator<T> {
   public:
    reverse_iterator() = default;
    reverse_iterator(T* p) : iterator<T>(p) {}
    reverse_iterator(const reverse_iterator& other)
        : iterator<T>(other.m_ptr) {}
    reverse_iterator& operator++() noexcept {
        iterator<T>::m_ptr--;
        return *this;
    }
    reverse_iterator operator++(int) noexcept {
        auto tmp = *this;
        iterator<T>::m_ptr--;
        return tmp;
    }
    reverse_iterator& operator--() noexcept {
        iterator<T>::m_ptr++;
        return *this;
    }
    reverse_iterator operator--(int) noexcept {
        auto tmp = *this;
        iterator<T>::m_ptr++;
        return tmp;
    }
    reverse_iterator& operator+=(const size_t pos) noexcept {
        iterator<T>::m_ptr -= pos;
        return *this;
    }
    reverse_iterator operator+(const size_t pos) const noexcept {
        auto tmp = *this;
        tmp -= pos;
        return tmp;
    }
    reverse_iterator& operator-=(const size_t pos) noexcept {
        iterator<T>::m_ptr += pos;
        return *this;
    }
    reverse_iterator operator-(const size_t pos) const noexcept {
        auto tmp = *this;
        tmp += pos;
        return tmp;
    }
    size_t operator-(const reverse_iterator other) const {
        return other.m_ptr - iterator<T>::m_ptr;
    }
};

template <class T>
class const_reverse_iterator : public reverse_iterator<T> {
   public:
    const_reverse_iterator() = default;
    const_reverse_iterator(T* p) : reverse_iterator<T>(p) {}
    const_reverse_iterator(const const_reverse_iterator& other)
        : reverse_iterator<T>(other.m_ptr) {}
    T& operator*() const noexcept = delete;
    T* operator->() const noexcept = delete;
};