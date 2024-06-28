#include <bits/stdc++.h>
// 通用随机访问迭代器模板
template<class Iter>
class GeneralRandomAccessIterator {
public:
    using value_type = typename std::iterator_traits<Iter>::value_type;
    using reference = typename std::iterator_traits<Iter>::reference;
    using pointer = typename std::iterator_traits<Iter>::pointer;
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = typename std::iterator_traits<Iter>::difference_type;

    GeneralRandomAccessIterator(Iter it) : it_(it) {}

    // 前置递增运算符
    GeneralRandomAccessIterator& operator++() {
        ++it_;
        return *this;
    }

    // 后置递增运算符
    GeneralRandomAccessIterator operator++(int) {
        GeneralRandomAccessIterator tmp(*this);
        ++(*this);
        return tmp;
    }

    // 前置递减运算符
    GeneralRandomAccessIterator& operator--() {
        --it_;
        return *this;
    }

    // 后置递减运算符
    GeneralRandomAccessIterator operator--(int) {
        GeneralRandomAccessIterator tmp(*this);
        --(*this);
        return tmp;
    }

    reference operator*() const { return *it_; }
    pointer operator->() const { return &(*it_); }

    // 加法运算符
    GeneralRandomAccessIterator operator+(difference_type n) const {
        return GeneralRandomAccessIterator(it_ + n);
    }

    // 减法运算符
    GeneralRandomAccessIterator operator-(difference_type n) const {
        return GeneralRandomAccessIterator(it_ - n);
    }

    // 赋值运算符
    reference operator[](difference_type n) const {
        return it_[n];
    }

    bool operator==(const GeneralRandomAccessIterator& other) const { return it_ == other.it_; }
    bool operator!=(const GeneralRandomAccessIterator& other) const { return !(*this == other); }
    bool operator<(const GeneralRandomAccessIterator& other) const { return it_ < other.it_; }
    bool operator<=(const GeneralRandomAccessIterator& other) const { return it_ <= other.it_; }
    bool operator>(const GeneralRandomAccessIterator& other) const { return it_ > other.it_; }
    bool operator>=(const GeneralRandomAccessIterator& other) const { return it_ >= other.it_; }

private:
    Iter it_;
};