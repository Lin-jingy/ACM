#include <corecrt.h>

template <class T>
class iterator {
   private:
    T* m_ptr;

   public:
    iterator() = default;
    iterator(T* p) : m_ptr(p) {}
    ~iterator() = default;
    iterator& operator=(const iterator& ptr) = default;
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
    friend bool operator==(const iterator a, const iterator b) noexcept {
        return a.m_ptr == b.m_ptr;
    }
    friend bool operator!=(const iterator a, const iterator b) noexcept {
        return a.m_ptr != b.m_ptr;
    }
};

template <class T>
class const_iterator : public iterator<T> {
   public:
    T& operator*() const noexcept = delete;
    T* operator->() const noexcept = delete;
};

template <class T>
class reverse_iterator {
    friend iterator<T>;

   private:
    T* m_ptr;

   public:
    reverse_iterator() = default;
    reverse_iterator(T* p) : m_ptr(p) {}
    reverse_iterator(const iterator<T>& p) : m_ptr(p.m_ptr) {}
    ~reverse_iterator() = default;
    reverse_iterator& operator=(const reverse_iterator& ptr) = default;
    T& operator*() const noexcept { return *m_ptr; }
    T* operator->() const noexcept { return m_ptr; }
    reverse_iterator& operator++() noexcept {
        --m_ptr;
        return *this;
    }
    reverse_iterator operator++(int) noexcept {
        reverse_iterator mid(*this);
        --m_ptr;
        return mid;
    }
    reverse_iterator& operator--() noexcept {
        ++m_ptr;
        return *this;
    }
    reverse_iterator operator--(int) noexcept {
        reverse_iterator mid(*this);
        ++m_ptr;
        return mid;
    }
    reverse_iterator& operator+=(const size_t pos) noexcept {
        m_ptr -= pos;
        return *this;
    }
    reverse_iterator operator+(const size_t pos) const noexcept {
        reverse_iterator mid(*this);
        m_ptr -= pos;
        return mid;
    }
    reverse_iterator& operator-=(const size_t pos) noexcept {
        m_ptr += pos;
        return *this;
    }
    reverse_iterator operator-(const size_t pos) const noexcept {
        reverse_iterator mid(*this);
        m_ptr += pos;
        return mid;
    }
    friend bool operator==(const reverse_iterator a,
                           const reverse_iterator b) noexcept {
        return a.m_ptr == b.m_ptr;
    }
    friend bool operator!=(const reverse_iterator a,
                           const reverse_iterator b) noexcept {
        return a.m_ptr != b.m_ptr;
    }
};

template <class T>
class const_reverse_iterator : public reverse_iterator<T> {
   public:
    T& operator*() const noexcept = delete;
    T* operator->() const noexcept = delete;
};