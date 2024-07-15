#include <bits/stdc++.h>

template <class T>
class rangeArray {
private:
    int l;
    std::vector<T> m_data;
public:
    constexpr rangeArray(int n) : l(0), m_data(n) {}
    constexpr rangeArray(int L, int R) : l(L), m_data(R - L + 1) {}
    constexpr T& operator[] (int pos) {
        return m_data.at(pos - l);
    }
    constexpr const T& operator[] (int pos) const {
        return m_data.at(pos - l);
    }
};
