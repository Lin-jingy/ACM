#include <bits/stdc++.h>

template <class T>
class sparseTable {
   private:
    std::vector<std::vector<T>> ST;
    std::function<T(const T, const T)> _func;
    static T default_func(const T t1, const T t2) { return std::max(t1, t2); }

   public:
    sparseTable(const std::vector<T> &v, auto func = default_func) {
        _func = func;
        int len = v.size();
        int L1 = std::__lg(len) + 1;
        ST.assign(len, std::vector<T>(L1));
        for (int i = 0; i < len; ++i) ST[i][0] = v[i];

        for (int j = 1; j < L1; ++j) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < len; ++i) {
                ST[i][j] = func(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T operator()(int l, int r) {
        int q = std::__lg(r - l + 1);
        return _func(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};