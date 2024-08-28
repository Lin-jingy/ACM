
#include <math.h>

#include <stdexcept>
#include <utility>

#include "iterator.hpp"

template <class T, class Allocator = std::allocator<T>>
class Vector {
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = std::allocator_traits<Allocator>::pointer;
    using const_pointer = std::allocator_traits<Allocator>::const_pointer;
    using iterator = iterator<T>;
    using const_iterator = const_iterator<T>;
    using reverse_iterator = reverse_iterator<T>;
    using const_reverse_iterator = const_reverse_iterator<T>;

    constexpr static bool is_trivial = std::is_trivial<T>::value;
    constexpr static float expansion_factor = 2.0f;

   private:
    void range_structure(iterator begin, iterator end, const_reference value) {
        if constexpr (is_trivial) return;
        while (begin != end) {
            *begin = T(value);
            ++begin;
        }
    }
    void range_destroy(iterator begin, iterator end) {
        if constexpr (is_trivial) return;
        while (begin != end) {
            *begin = ~T();
            ++begin;
        }
    }
    iterator apply(int n) { m_alloc.allocate(n); }
    iterator apply_all() { m_alloc.allocate(m_end_of_storage - m_begin); }
    void release_all() {
        m_alloc.deallocate(m_begin, m_end_of_storage - m_begin);
    }

   public:
    constexpr Vector() noexcept(noexcept(Allocator())) = default;
    constexpr explicit Vector(const Allocator &alloc) noexcept
        : m_alloc(alloc) {}
    constexpr Vector(size_type count, const T &value,
                     const Allocator &alloc = Allocator())
        : m_alloc(alloc) {
        this(count);
        range_structure(m_begin, m_end, value);
    }
    constexpr explicit Vector(size_type count,
                              const Allocator &alloc = Allocator()) {
        m_end = m_begin + count;
        m_end_of_storage = m_end;
        m_begin = apply_all();
    }
    template <class InputIt>
    constexpr Vector(InputIt first, InputIt last,
                     const Allocator &alloc = Allocator()) {
        this(last - first);
        iterator it = m_begin;
        std::copy(first, last, m_begin);
    }
    constexpr Vector(const Vector &other) {
        m_alloc = other.m_alloc;
        size_type capacity = other.m_end_of_storage - other.m_begin;
        size_type size = other.m_end - other.m_begin;
        m_end = m_begin + size;
        m_end_of_storage = m_begin + capacity;
        m_begin = apply_all();
        std::copy(other.m_begin, other.m_end, m_begin);
    }
    constexpr Vector(const Vector &other, const Allocator &alloc)
        : m_alloc(alloc) {
        size_type capacity = other.m_end_of_storage - other.m_begin;
        size_type size = other.m_end - other.m_begin;
        m_end = m_begin + size;
        m_end_of_storage = m_begin + capacity;
        m_begin = apply_all();
        std::copy(other.m_begin, other.m_end, m_begin);
    }
    constexpr Vector(Vector &&other)
        : m_alloc(other.m_alloc),
          m_begin(other.m_begin),
          m_end(other.m_end),
          m_end_of_storage(other.m_end_of_storage) {}
    constexpr Vector(Vector &&other, const Allocator &alloc)
        : m_alloc(alloc),
          m_begin(other.m_begin),
          m_end(other.m_end),
          m_end_of_storage(other.m_end_of_storage) {}
    constexpr Vector(std::initializer_list<T> init,
                     const Allocator &alloc = Allocator())
        : m_alloc(alloc) {
        m_end = m_begin + init.size();
        m_end_of_storage = m_end;
        m_begin = apply_all();
        std::copy(init.begin(), init.end(), m_begin);
    }
    constexpr ~Vector() {
        range_destroy(m_begin, m_end);
        release_all();
    }

    constexpr Vector &operator=(const Vector &other) {
        range_destroy(m_begin, m_end);
        size_type size = other.size();
        m_begin = apply(size);
        m_end = m_begin + size;
        m_end_of_storage = m_begin + other.capacity();
        m_alloc = other.m_alloc;
        std::copy(other.begin(), other.end(), m_begin);
    }
    constexpr Vector &operator=(Vector &&other) noexcept {
        m_begin = other.m_begin;
        m_end = other.m_end;
        m_end_of_storage = other.m_end_of_storage;
        m_alloc = other.m_alloc;
    }
    constexpr Vector &operator=(std::initializer_list<value_type> ilist) {
        m_end = m_begin + ilist.size();
        m_end_of_storage = m_end;
        m_begin = apply_all();
        std::copy(ilist.begin(), ilist.end(), m_begin);
    }

    constexpr void assign(size_type count, const T &value) {
        if (count < size()) range_destroy(m_begin + count, m_end);
        reserve(count);
        m_end = m_begin + count;
        range_structure(m_begin, m_end, value);
    }

    template <class InputIt>
    constexpr void assign(InputIt first, InputIt last) {
        size_type size = last - first;
        if (size < this->size()) ange_destroy(m_begin + size, m_end);
        reserve(size);
        m_end = m_begin + size;
        for (auto it = m_begin; it != m_end; ++it, ++first) *it = *first;
    }

    constexpr void assign(std::initializer_list<T> ilist) {
        if (ilist.size() < this->size())
            range_destroy(m_begin + ilist.size(), m_end);
        reserve(ilist.size());
        m_end = m_begin + ilist.size();
        std::copy(ilist.begin(), ilist.end(), m_begin);
    }

    constexpr allocator_type get_allocator() const { return m_alloc; }

    // ?元素访问
    constexpr reference at(size_type pos) {
        if (pos >= size()) throw std::out_of_range("");
        return *(m_begin + pos);
    }
    constexpr const_reference at(size_type pos) const {
        if (pos >= size()) throw std::out_of_range("");
        return *(m_begin + pos);
    }

    constexpr reference operator[](size_type pos) { return *(m_begin + pos); }
    constexpr const_reference operator[](size_type pos) const {
        return *(m_begin + pos);
    }

    constexpr reference front() { return *m_begin; }
    constexpr const_reference front() const { return *m_begin; }

    constexpr reference back() { return *(m_end - 1); }
    constexpr const_reference back() const { return *(m_end - 1); }

    constexpr T *data() { return m_begin; }
    constexpr const T *data() const { return m_begin; }

    // ?迭代器
    constexpr iterator begin() { return m_begin; }
    constexpr const_iterator begin() const { return const_iterator(m_begin); }
    constexpr const_iterator cbegin() const noexcept {
        return const_iterator(m_begin);
    }
    constexpr iterator end() noexcept { return m_end; }
    constexpr const_iterator end() const noexcept {
        return const_iterator(m_end);
    }
    constexpr const_iterator cend() const noexcept {
        return const_iterator(m_end);
    }
    constexpr reverse_iterator rbegin() { return ++reverse_iterator(m_end); }
    constexpr const_reverse_iterator rbegin() const {
        return ++const_reverse_iterator(m_end);
    }
    constexpr const_reverse_iterator crbegin() const noexcept {
        return ++const_reverse_iterator(m_end);
    }
    constexpr reverse_iterator rend() { return ++reverse_iterator(m_begin); }
    constexpr const_reverse_iterator rend() const {
        return ++const_reverse_iterator(m_begin);
    }
    constexpr const_reverse_iterator crend() const noexcept {
        return ++const_reverse_iterator(m_begin);
    }

    // ?容量
    constexpr bool empty() const { return m_begin == m_end; }
    constexpr size_type size() const {
        return static_cast<size_type>(m_end - m_begin);
    }
    constexpr size_type max_size() const {
        return std::numeric_limits<difference_type>::max();
    }
    constexpr void reserve(size_type new_cap) {
        if (new_cap <= size()) return;
        iterator new_begin = apply(new_cap);
        iterator new_end = new_begin + this->size();
        for (auto new_it = new_begin, last_it = m_begin; new_it != new_end;
             ++new_it, ++last_it) {
            *new_it = std::move(*last_it);
        }
        release_all();
        m_begin = new_begin;
        m_end = new_end;
        m_end_of_storage = m_begin + new_cap;
    }
    constexpr size_type capacity() const { return m_end_of_storage - m_begin; }
    constexpr void shrink_to_fit() {
        size_type size = this->size();
        iterator new_begin = apply(size);
        iterator new_end = new_begin + this->size();
        for (auto new_it = new_begin, last_it = m_begin; new_it != new_end;
             ++new_it, ++last_it) {
            *new_it = std::move(*last_it);
        }
        release_all();
        m_begin = new_begin;
        m_end = new_end;
        m_end_of_storage = m_begin + size;
    }
    // ?修改器
    constexpr void clear() {
        range_destroy(m_begin, m_end);
        m_end = m_begin;
    }
    constexpr iterator insert(const_iterator pos, const T &value) {
        // 检查容量并重新分配内存
        if (m_end == m_end_of_storage) {
            // 计算插入位置
            size_type index = pos - m_begin;
            // 扩容
            reserve(size() * expansion_factor);
            // 重新赋值pos
            pos = m_begin + index;
        }
        // 移动元素
        for (auto it = m_end; it != pos; --it) *it = std::move(*(it - 1));
        // 在 pos 位置拷贝构造新元素
        *pos = value;
        // 更新 m_end
        m_end++;
        return pos;
    }

    constexpr iterator insert(const_iterator pos, T &&value) {
        // 检查容量并重新分配内存
        if (m_end == m_end_of_storage) {
            // 计算插入位置
            size_type index = pos - m_begin;
            reserve(size() * expansion_factor);
            // 重新赋值pos
            pos = m_begin + index;
        }
        // 移动元素
        for (auto it = m_end; it != pos; --it) *it = std::move(*(it - 1));
        // 在 pos 位置移动构造新元素
        *pos = std::move(value);
        // 更新 m_end
        m_end++;
        return iterator(pos);
    }

    constexpr iterator insert(const_iterator pos, size_type count,
                              const T &value) {
        // 检查容量并重新分配内存
        if (m_end + count - 1 == m_end_of_storage) {
            // 计算插入位置
            size_type index = pos - m_begin;
            reserve(std::max(size() * expansion_factor, size() + count));
            // 重新赋值pos
            pos = m_begin + index;
        }
        // 移动元素
        for (auto it = m_end + count - 1; it != pos; ++it)
            *it = std::move(*(it - count));
        // 在 pos以及其后count个位置拷贝构造新元素
        for (auto it = pos; it != pos + count; ++it) *it = value;
        // 更新 m_end
        m_end += count;
        return iterator(pos);
    }

    template <class InputIt>
    constexpr iterator insert(const_iterator pos, InputIt first, InputIt last) {
        // 计算插入大小
        size_type count = static_cast<size_type>(last - first);
        // 检查容量并重新分配内存
        if (m_end + count - 1 == m_end_of_storage) {
            // 计算插入位置
            size_type index = pos - m_begin;
            // 扩容
            reserve(std::max(size() * expansion_factor, size() + count));
            // 重新赋值pos
            pos = m_begin + index;
        }
        // 移动元素
        for (auto it = m_end + count - 1; it != pos; ++it)
            *it = std::move(*(it - count));
        // 拷贝构造元素
        std::copy(first, last, pos);
        // 更新 m_end
        m_end += count;
        return iterator(pos);
    }

    constexpr iterator insert(const_iterator pos,
                              std::initializer_list<T> ilist) {
        // 计算插入大小
        size_type count = ilist.size();
        // 检查容量并重新分配内存
        if (m_end + count - 1 == m_end_of_storage) {
            // 计算插入位置
            size_type index = pos - m_begin;
            // 扩容
            reserve(std::max(size() * expansion_factor, size() + count));
            // 重新赋值pos
            pos = m_begin + index;
        }
        // 移动元素
        for (auto it = m_end + count - 1; it != pos; ++it)
            *it = std::move(*(it - count));
        // 拷贝构造元素
        std::copy(ilist.begin(), ilist.end(), pos);
        // 更新 m_end
        m_end += count;
        return iterator(pos);
    }

    template <class... Args>
    constexpr iterator emplace(const_iterator pos, Args &&...args) {
        // 检查容量并重新分配内存
        if (m_end == m_end_of_storage) {
            // 计算插入位置
            size_type index = pos - m_begin;
            // 扩容
            reserve(size() * expansion_factor);
            // 重新赋值pos
            pos = m_begin + index;
        }
        // 移动元素
        for (auto it = m_end; it != pos; --it) *it = std::move(*(it - 1));
        // 在 pos 位置构造新元素
        *pos = T(std::forward<Args>(args)...);
        // 更新 m_end
        m_end++;
        return iterator(pos);
    }

    constexpr iterator erase(const_iterator pos) {
        // 销毁元素
        pos->~T();
        // 移动元素
        for (auto it = pos; it != m_end - 1; ++it) *it = std::move(*(it + 1));
        // 更新 m_end
        --m_end;
        if (size() * expansion_factor < capacity()) {
            // 计算下一个位置
            size_type index = pos - m_begin;
            // 缩小空间
            shrink_to_fit();
            // 重新赋值pos
            pos = m_begin + index;
        }
        return iterator(pos);
    }

    constexpr iterator erase(const_iterator first, const_iterator last) {
        // 销毁元素
        range_destroy(first, last);
        // 计算大小
        size_type size = static_cast<size_type>(last - first);
        // 移动元素
        for (auto it = first; it != m_end - size; ++it)
            *it = std::move(*(it + size));
        // 更新 m_end
        m_end -= size;
        if (this->size() * expansion_factor < capacity()) {
            // 计算下一个位置
            size_type index = last - m_begin;
            // 缩小空间
            shrink_to_fit();
            // 重新赋值last
            last = m_begin + index;
        }
        return iterator(last);
    }

    constexpr void push_back(const T &value) {
        // 检查容量并重新分配内存
        if (m_end == m_end_of_storage) {
            // 扩容
            reserve(size() * expansion_factor);
        }
        // 拷贝构造元素
        *m_end = value;
        // 更新 m_end
        ++m_end;
    }

    constexpr void push_back(T &&value) {
        // 检查容量并重新分配内存
        if (m_end == m_end_of_storage) {
            // 扩容
            reserve(size() * expansion_factor);
        }
        // 移动构造元素
        *m_end = std::move(value);
        // 更新 m_end
        ++m_end;
    }

    template <class... Args>
    constexpr reference emplace_back(Args &&...args) {
        // 检查容量并重新分配内存
        if (m_end == m_end_of_storage) {
            // 扩容
            reserve(size() * expansion_factor);
        }
        // 原地构造元素
        *m_end = T(std::forward<Args>(args)...);
        // 更新 m_end
        ++m_end;
        return *m_end;
    }

    constexpr void pop_back() {
        // 销毁元素
        (m_end - 1)->~T();
        // 更新 m_end
        --m_end;
        // 检查容量并缩小空间
        if (size() * expansion_factor < capacity()) shrink_to_fit();
    }

    constexpr void resize(size_type count) {
        // 如果当前大小大于count
        if (size() > count) {
            // 销毁多余部分
            range_destroy(m_begin + count, m_end);
            // 重新赋值 m_end
            m_end = m_begin + count;
            // 检查容量并缩小空间
            if (size() * expansion_factor < capacity()) shrink_to_fit();
        } else if (size() < count) {
            reserve(count);
        }
    }

    constexpr void resize(size_type count, const value_type &value) {
        // 如果当前大小大于count
        if (size() > count) {
            // 销毁多余部分
            range_destroy(m_begin + count, m_end);
            // 重新赋值 m_end
            m_end = m_begin + count;
            // 检查容量并缩小空间
            if (size() * expansion_factor < capacity()) shrink_to_fit();
        } else if (size() < count) {
            iterator last_end = m_end;
            reserve(count);
            // 对于新分配的空间进行拷贝构造
            for (auto it = last_end; it != m_end; ++it) *it = value;
        }
    }

    constexpr void swap(Vector &other) noexcept {
        std::swap(m_begin, other.m_begin);
        std::swap(m_end, other.m_end);
        std::swap(m_end_of_storage, other.m_end_of_storage);
        std::swap(m_alloc, other.m_alloc);
    }

    constexpr bool operator==(const Vector &other) const {
        return size() == other.size() &&
               std::equal(m_begin, m_end, other.m_begin, other.m_end);
    }

    constexpr auto operator<=>(const Vector &other) const {
        if (size() == other.size()) {
            return std::lexicographical_compare_three_way(
                m_begin, m_end, other.m_begin, other.m_end);
        }
        return size() <=> other.size();
    }

   private:
    iterator m_begin;
    iterator m_end;
    iterator m_end_of_storage;
    Allocator m_alloc = std::allocator<T>();
};

namespace std {
template <class T, class Alloc>
void swap(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs) noexcept {
    lhs.swap(rhs);
}
}  // namespace std
