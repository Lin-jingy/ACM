#include <bits/stdc++.h>

#include <stdexcept>

template <class T>
class deque {
   public:
    deque() = default;

    // 容量
    bool empty() { return m_begin == m_end; }
    size_t size() {
        if (m_begin <= m_end) return m_end - m_begin;
        else
            return m_data.size() - m_begin + m_end;
    }
    size_t max_size() { return m_data.max_size(); }
    void shrink_to_fit() {
        if (empty()) return;
        std::vector<T> m_tmp(size());
        if (m_begin <= m_end)
            std::copy(m_data.begin() + m_begin, m_data().begin() + m_end,
                      m_tmp.begin());
        else {
            std::copy(m_data.begin() + m_begin, m_data.end(), m_tmp.begin());
            std::copy(m_data.begin(), m_data.begin() + m_end,
                      m_tmp.begin() + m_data.size() - m_begin);
        }
        m_data = std::move(m_tmp);
    }
    // 元素访问
    T& operator[](size_t pos) {
        if (m_begin + pos < m_data.size()) return m_data[m_begin + pos];
        else
            return m_data[pos - (m_data.size() - m_begin)];
    }

    const T& operator[](size_t pos) const { return operator[](pos); }

    T& at(size_t pos) {
        if (pos >= size()) throw std::out_of_range("");
        return operator[](pos);
    }

    const T& at(size_t pos) const { return at(pos); }

    T& front() { return m_data[m_begin]; }
    const T& front() const { return front(); }

    T& back() { return m_data[m_end]; }
    const T& back() const { return back(); }

    // 迭代器
    class iterator : public std::vector<T>::iterator {
        using fiter = std::vector<T>::iterator;
        iterator() : fiter() {}
        iterator(iterator&& other) : fiter(std::forward<iterator&&>(other)) {}
        iterator& operator++() {
            fiter::operator++();
            if (*this == m_data.end()) *this = m_data.begin();
            return this;
        }
        iterator& operator++(int) {
            iterator tmp(*this);
            operator++();
            return tmp;
        }
        iterator& operator--() {
            if (*this == m_data.begin()) *this = --m_data.end();
            else
                fiter::operator--();
            return this;
        }
        iterator& operator--(int) {
            iterator tmp(*this);
            operator--();
            return tmp;
        }
        iterator& operator+=(size_t pos) {
            
        }
    };
    class const_iterator : public iterator {
        T& operator*() const noexcept = delete;
        T* operator->() const noexcept = delete;
    };
    iterator begin() { return m_data.begin() + m_begin; }

    //  修改
    void clear() {
        m_begin = m_end = 0;
        m_data.clear();
    }

   private:
    std::vector<T> m_data;
    size_t m_begin, m_end;
};
