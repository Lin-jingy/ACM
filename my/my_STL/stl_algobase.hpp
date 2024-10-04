#include <type_traits>
#include <utility>

namespace mystl {

template <class T>
typename std::remove_reference<T>::type&& move(T&& t) {
    return static_cast<typename std::remove_reference<T>::type&&>(t);
}

template <class T>
void swap(T& l, T& r) {
    T tmp = move(l);
    l = move(r);
    r = move(tmp);
}

template <class T>
const T& min(const T& a, const T& b) {
    if (a < b) return a;
    else return b;
}

template <class T>
const T& max(const T& a, const T& b) {
    if (b < a) return a;
    else return b;
}

template <class in_iter, class out_iter>
void copy(in_iter first, in_iter last, out_iter result) {
    for (; first != last; ++first, ++result) *result = *first;
}

template <class in_iter, class out_iter>
void copy_backward(in_iter first, in_iter last, out_iter result) {
    for (--result; first != last; ++first, --result) *result = *first;
}

template <class in_iter, class out_iter>
void copy_n(in_iter first, std::size_t size, out_iter result) {
    for (std::size_t i = 0; i < size; ++i, ++first, ++result) *result = *first;
}

template <class iter, class T>
void fill(iter first, iter last, const T& value) {
    for (; first != last; ++first) *first = value;
}

template <class iter, class T>
void fill_n(iter first, std::size_t size, const T& value) {
    for (std::size_t i = 0; i < size; ++i, ++first) *first = value;
}

template <class iter1, class iter2>
std::pair<iter1, iter2> mismatch(iter1 first1, iter1 last1, iter2 first2) {
    for (; first1 != last1 && *first1 == *first2; ++first1, ++first2)
        ;
    return std::make_pair(first1, first2);
}

template <class iter1, class iter2, class Func>
std::pair<iter1, iter2> mismatch(iter1 first1, iter1 last1, iter2 first2,
                                 Func isEqual) {
    for (; first1 != last1 && isEqual(*first1, *first2); ++first1, ++first2)
        ;
    return std::make_pair(first1, first2);
}

template <class iter1, class iter2>
bool equal(iter1 first1, iter1 last1, iter2 first2) {
    for (; first1 != last1; ++first1, ++first2)
        if (*first1 != *first2) return false;
    return true;
}

template <class iter1, class iter2, class Func>
bool equal(iter1 first1, iter1 last1, iter2 first2, Func isEqual) {
    for (; first1 != last1; ++first1, ++first2)
        if (!isEqual(*first1, *first2)) return false;
    return true;
}

template <class iter1, class iter2>
bool lexicographical_compare(iter1 first1, iter1 last1, iter2 first2,
                             iter2 last2) {
    for (; first1 != last1 && first2 != last2; ++first1, ++first2)
        if (*first1 < *first2) return true;
        else if (*first2 < *first1) return false;
    return first1 == last1 && first2 != last2;
}

template <class iter1, class iter2, class Func>
bool lexicographical_compare(iter1 first1, iter1 last1, iter2 first2,
                             iter2 last2, Func comp) {
    for (; first1 != last1 && first2 != last2; ++first1, ++first2)
        if (comp(*first1, *first2)) return true;
        else if (comp(*first2, *first1)) return false;
    return first1 == last1 && first2 != last2;
}

}  // namespace mystl