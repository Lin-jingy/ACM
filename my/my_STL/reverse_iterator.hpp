#include <cstddef>

template <class T, class Iterator>
class reverse_iterator {
   public:
    reverse_iterator() = default;
    reverse_iterator(const Iterator &iter) : m_iter(iter) {}
    reverse_iterator(const reverse_iterator &iter) : m_iter(iter.m_iter) {}
    ~reverse_iterator() = default;

    Iterator base() const { return m_iter; }
    T &operator*() const {  // 实际对应正向迭代器的前一个位置
        auto tmp = m_iter;
        return *--tmp;
    }
    T *operator->() const { return &(operator*()); }
    reverse_iterator &operator++() {
        --m_iter;
        return *this;
    }
    reverse_iterator operator++(int) {
        auto tmp = *this;
        --m_iter;
        return tmp;
    }
    reverse_iterator &operator--() {
        ++m_iter;
        return *this;
    }
    reverse_iterator operator--(int) {
        auto tmp = *this;
        ++m_iter;
        return tmp;
    }
    reverse_iterator &operator+=(size_t pos) {
        m_iter -= pos;
        return *this;
    }
    reverse_iterator operator+(size_t pos) {
        return reverse_iterator(m_iter - pos);
    }
    reverse_iterator &operator-=(size_t pos) {
        m_iter += pos;
        return *this;
    }
    reverse_iterator operator-(size_t pos) {
        return reverse_iterator(m_iter + pos);
    }

   private:
    Iterator m_iter;
};