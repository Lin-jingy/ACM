#include <bits/stdc++.h>

template<class T, size_t size>
class array {
private:
    T m_data[size];
public:
    array() = default;
    ~array() = default;

    //Element access
    constexpr T& at(size_t pos) {
        if(pos < 0 or pos >= size) throw std::out_of_range("err=>at()");
        return m_data[pos];
    }
    constexpr const T& at(size_t pos) const {
        if(pos < 0 or pos >= size) throw std::out_of_range("err=>at()");
        return m_data[pos];
    }
    constexpr T& operator[](size_t pos) noexcept {
        return m_data[pos];
    }
    constexpr const T& operator[](size_t pos) const noexcept {
        return m_data[pos];
    }
    constexpr T& front() noexcept {
        return m_data[0];
    }
    constexpr const T& front() const noexcept {
        return m_data[0];
    }
    constexpr T& back() noexcept {
        return m_data[size - 1];
    }
    constexpr const T& back() const noexcept {
        return m_data[size - 1];
    }
    constexpr T* data() noexcept {
        return m_data;
    }
    constexpr const T* data() const noexcept {
        return m_data;
    }
    
    //Iterators
    class iterator {
    private:
        T *m_ptr;
    public:
        iterator() = default;
        ~iterator() = default;
        iterator(T *ptr) : m_ptr(ptr){}
        iterator(const iterator &ptr): m_ptr(ptr.m_ptr){}
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
    class const_iterator : public iterator {
        T& operator*() const noexcept = delete;
        T* operator->() const noexcept = delete;
    };
    class reverse_iterator : public iterator {
        iterator& operator++() noexcept {
            return iterator::operator--();
        }
        iterator operator++(int) noexcept {
            return iterator::operator()--;
        }
        iterator& operator--() noexcept {
            return iterator::operator++();
        }
        iterator operator--(int) noexcept {
            return iterator::operator()++;
        }
        iterator& operator+=(const size_t pos) noexcept {
            return iterator::operator+=(pos);
        }
        iterator operator+(const size_t pos) const noexcept {
            return iterator::operator+(pos);
        }
        iterator& operator-=(const size_t pos) noexcept {
            return iterator::operator-=(pos);
        }
        iterator operator-(const size_t pos) const noexcept {
            return iterator::operator-(pos);
        }
    };
    class const_reverse_iterator : public reverse_iterator {
        T& operator*() const noexcept = delete;
        T* operator->() const noexcept = delete;
    };
    iterator begin() noexcept {
        return iterator(m_data);
    }
    const_iterator begin() const noexcept {
        return const_iterator(m_data);
    }
    iterator end() noexcept {
        return iterator(m_data + size);
    }
    const_iterator end() const noexcept {
        return const_iterator(m_data + size);
    }
    reverse_iterator rbegin() noexcept {
        return reverse_iterator(m_data + size - 1);
    }
    const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator(m_data + size - 1);
    }
    reverse_iterator rend() noexcept {
        return reverse_iterator(m_data - 1);
    }
    const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator(m_data - 1);
    }
};

int main() {
    
}