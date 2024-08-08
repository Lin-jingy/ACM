#include <bits/stdc++.h>

// 只能用于正数
template <class T>
constexpr void radix_sort(std::vector<T> &a) {
    T p[20] = {1};
    if constexpr (std::is_same<T, int>::value) {
        for (int i = 1; i < 10; ++i) p[i] = p[i - 1] * 10;
    } else if constexpr (std::is_same<T, long long>::value) {
        for (int i = 1; i < 19; ++i) p[i] = p[i - 1] * 10;
    } else
        assert(0);

    std::array<std::vector<T>, 10> bucket;
    std::vector<T> list = a;

    for (int i = 0;; ++i) {
        bool f = 0;
        for (auto j : list) {
            T x = j / p[i];
            if (x != 0) f = 1;
            bucket[x % 10].push_back(j);
        }
        list.clear();
        for (auto &j : bucket)
            for (auto &k : j) list.push_back(k);
        for (auto &j : bucket) j.clear();
        if (!f) break;
    }
    a = std::move(list);
}

constexpr void radix_sort(auto begin, auto end) {
    int p[20] = {1};
    for (int i = 1; i < 19; ++i) p[i] = p[i - 1] * 10;

    std::array<std::vector<int>, 10> bucket;
    std::vector list(begin, end);

    for (int i = 0;; ++i) {
        bool f = 0;
        for (auto j : list) {
            auto x = j / p[i];
            if (x != 0) f = 1;
            bucket[x % 10].push_back(j);
        }
        list.clear();
        for (auto &j : bucket)
            for (auto &k : j) list.push_back(k);
        for (auto &j : bucket) j.clear();
        if (!f) break;
    }
    int pos = 0;
    for (auto it = begin; it != end; ++it) *it = list[pos++];
}
