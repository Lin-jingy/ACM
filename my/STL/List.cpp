#include <iterator>
#include <limits>

template <class T>
class List {
    struct node {
        T data;
        node *prev, *next;
    };

   public:
    class iterator;
    class const_iterator;

    class iterator {
       public:
        iterator() = default;
        iterator(node *ptr) : m_ptr(ptr) {}
        iterator(const iterator &other) : m_ptr(other.m_ptr) {}
        bool operator==(const iterator &other) const {
            return m_ptr == other.m_ptr;
        }
        bool operator!=(const iterator &other) const {
            return m_ptr != other.m_ptr;
        }
        T &operator*() const { return m_ptr->data; }
        T *operator->() const { return &(operator*()); }
        operator const_iterator() const { return const_iterator(m_ptr); }

        iterator &operator++() {
            m_ptr = m_ptr->next;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }
        iterator operator+(size_t n) {
            iterator tmp = *this;
            while (n--) ++tmp;
            return tmp;
        }
        iterator &operator+=(size_t n) {
            while (n--) ++*this;
        }
        iterator &operator--() {
            m_ptr = m_ptr->prev;
            return *this;
        }
        iterator operator--(int) {
            iterator tmp = *this;
            --*this;
            return tmp;
        }
        iterator operator-(size_t n) {
            iterator tmp = *this;
            while (n--) --tmp;
            return tmp;
        }
        iterator &operator-=(size_t n) {
            while (n--) --*this;
        }

       protected:
        node *m_ptr;
    };
    class const_iterator : public iterator {
       public:
        const_iterator() = default;
        const_iterator(node *ptr) : iterator(ptr) {}
        const_iterator(const const_iterator &other) : iterator(other) {}
        operator iterator() const { return iterator(iterator::m_ptr); }
        T &operator*() const = delete;
        T *operator->() const = delete;
    };
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    friend iterator;
    friend const_iterator;
    friend reverse_iterator;
    friend const_reverse_iterator;

   public:
    List() = default;
    ~List() {}

    // 元素访问
    T &front() { return *begin(); }
    const T &front() const { return *begin(); }
    T &back() { return *rbegin(); }
    const T &back() const { *rbegin(); }

    // 迭代器
    iterator begin() noexcept { return iterator(m_node->next); }
    const_iterator begin() const noexcept {
        return const_iterator(m_node->next);
    }
    const_iterator cbegin() const noexcept {
        return const_iterator(m_node->next);
    }
    iterator end() noexcept { return iterator(m_node); }
    const_iterator end() const noexcept { return const_iterator(m_node); }
    const_iterator cend() const noexcept { return const_iterator(m_node); }
    reverse_iterator rbegin() noexcept { return reverse_iterator(--end()); }
    const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator(--end());
    }
    const_reverse_iterator crbegin() const noexcept {
        return const_reverse_iterator(--end());
    }
    reverse_iterator rend() noexcept { return reverse_iterator(--begin()); }
    const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator(--begin());
    }
    const_reverse_iterator crend() const noexcept {
        return const_reverse_iterator(--begin());
    }

    // 容量
    bool empty() const { return begin() == end(); }
    size_t size() const noexcept { return m_size; }
    size_t max_size() const { return std::numeric_limits<size_t>::max(); }

    // 修改
    void clear() {
        m_size = 0;
        for (auto it = m_node->next; it != m_node;) {
            auto next = it->next;
            free(it);
        }
    }
    iterator insert(const_iterator pos, const T &value) {
        auto prev = pos.m_ptr;
        node *tmp = malloc(sizeof(node));
    }
    iterator insert(const_iterator pos, T &&value) {}

   private:
    node *m_node = static_cast<node *>(malloc(sizeof(node)));
    size_t m_size = 0;
};

#include <list>
int main() {
    List<int> l;
    List<int>::const_iterator it = l.begin();
    List<int>::iterator it1 = it;

    std::list<int> list;
    std::list<int>::const_iterator ll = list.begin();
}