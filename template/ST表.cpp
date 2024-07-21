#include <bits/stdc++.h>



template <class T>
class sparseTable {
private:
    std::vector<std::vector<T>> ST;
    std::function<T(const T, const T)> _func;
public:
    sparseTable(const std::vector<T> &&v, auto func) {
        _func = func;
        int len = v.size();
        int L1 = std::__lg(len);
        ST.assign(len, std::vector<T>(L1 + 1));
        for(int i = 0; i < len; ++i) ST[i][0] = v[i];

        for(int j = 1; j < L1; ++j) {
            int pj = (1 << (j - 1));
            for(int i = 0; i + pj < len; ++i) {
                ST[i][j] = func(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T operator() (int l, int r) {
        int q = std::__lg(r - l + 1) - 1;
        return _func(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};