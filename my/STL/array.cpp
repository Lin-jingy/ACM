#include <cstddef>
#include <stdexcept>
#include <utility>

template <class T, std::size_t N>
class Array {
 public:
  using value_type = T;
  using size_type = std::size_t;
  using difference_type = ptrdiff_t;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;

  Array() = default;
  Array(const Array<T, N>& other) {
    memcpy(m_data, other.m_data, sizeof(m_data));
  }
  Array(const std::initializer_list<int>& list) {
    int f = 0;
    for (auto& val : list) {
      m_data[f++] = val;
    }
  }
//   ~Array() = default;
  [[nodiscard]] constexpr reference at(size_type pos) {
    if (pos >= N or pos < 0) throw std::out_of_range("");
    return m_data[pos];
  }
  [[nodiscard]] constexpr const_reference at(size_type pos) const {
    if (pos >= N or pos < 0) throw std::out_of_range("");
    return m_data[pos];
  }
  [[nodiscard]] constexpr reference operator[](size_type pos) {
    return m_data[pos];
  }
  [[nodiscard]] constexpr const_reference operator[](size_type pos) const {
    return m_data[pos];
  }
  [[nodiscard]] constexpr reference front() { return m_data[0]; }
  [[nodiscard]] constexpr const_reference front() const { return m_data[0]; }
  [[nodiscard]] constexpr reference back() { return m_data[N - 1]; }
  [[nodiscard]] constexpr const_reference back() const { return m_data[N - 1]; }
  [[nodiscard]] constexpr pointer data() noexcept { return m_data; }
  [[nodiscard]] constexpr const_pointer data() const noexcept { return m_data; }
  class iterator {
   public:
    iterator() = default;
    ~iterator() = default;
    iterator(T* ptr) : m_ptr(ptr) {}
    iterator(const iterator& ptr) : m_ptr(ptr.m_ptr) {}
    T& operator*() const noexcept { return *m_ptr; }
    T* operator->() const noexcept { return m_ptr; }
    iterator& operator=(const iterator& ptr) { m_ptr = ptr; }
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

   private:
    T* m_ptr;
  };
  class const_iterator : public iterator {
    T& operator*() const noexcept = delete;
    T* operator->() const noexcept = delete;
  };
  class reverse_iterator : public iterator {
    iterator& operator++() noexcept { return iterator::operator--(); }
    iterator operator++(int) noexcept { return iterator::operator()--; }
    iterator& operator--() noexcept { return iterator::operator++(); }
    iterator operator--(int) noexcept { return iterator::operator()++; }
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

  [[nodiscard]] constexpr iterator begin() noexcept { return iterator(m_data); }
  [[nodiscard]] constexpr const_iterator begin() const noexcept {
    return const_iterator(m_data);
  }
  [[nodiscard]] constexpr const_iterator cbegin() const noexcept {
    return const_iterator(m_data);
  }
  [[nodiscard]] constexpr iterator end() noexcept {
    return iterator(m_data + N);
  }
  [[nodiscard]] constexpr const_iterator end() const noexcept {
    return const_iterator(m_data + N);
  }
  [[nodiscard]] constexpr const_iterator cend() const noexcept {
    return const_iterator(m_data + N);
  }
  [[nodiscard]] constexpr reverse_iterator rbegin() noexcept {
    return reverse_iterator(m_data + N - 1);
  }
  [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(m_data + N - 1);
  }
  [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept {
    return rbegin();
  }
  [[nodiscard]] constexpr reverse_iterator rend() noexcept {
    return reverse_iterator(m_data - 1);
  }
  [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(m_data - 1);
  }
  [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(m_data - 1);
  }
  [[nodiscard]] constexpr bool empty() const noexcept { return N == 0; }
  [[nodiscard]] constexpr size_type size() const noexcept { return N; }
  constexpr void fill(const_reference value) {
    for (auto it = begin(); it != end(); ++it) *it = value;
  }
  constexpr void swap(Array& other) noexcept {
    for (int i = 0; i < N; ++i) swap(m_data[i], other.m_data[i]);
  }
  constexpr bool operator==(const Array& other) const noexcept {
    for (int i = 0; i < N; ++i)
      if (m_data[i] != other.m_data[i]) return false;
    return true;
  }
  constexpr auto operator<=>(const Array& other) const noexcept {
    for (int i = 0; i < N; ++i) {
      if (m_data[i] > other.m_data[i])
        return 1;
      else if (m_data[i] < other.m_data[i])
        return -1;
    }
    return 0;
  }
  constexpr Array& operator=(const Array& other) noexcept {
    memcpy(m_data, other.m_data, sizeof(m_data));
  }

 private:
  T m_data[N];
};