#include <corecrt.h>


template <class T>
class iterator {
private:
    T *m_ptr;
public:
    iterator() = default;
    ~iterator() = default;
    iterator(const iterator &ptr): m_ptr(ptr){}
    T& operator*() const noexcept {
        return *m_ptr;
    }
    T* operator->() const noexcept {
        return m_ptr;
    }
    iterator& operator=(const iterator &ptr) {
        m_ptr = ptr;
    }
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
    friend bool operator==(const iterator a, const iterator b) {
        return a.m_ptr == b.m_ptr;
    }
    friend bool operator!=(const iterator a, const iterator b) {
        return a.m_ptr != b.m_ptr;
    }
};