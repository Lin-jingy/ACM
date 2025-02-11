#include <bits/stdc++.h>

template <class T>
class sparseTable {
   private:
    std::vector<std::vector<T>> ST;
    std::function<T(const T &, const T &)> _func;

   public:
    static T max(const T &t1, const T &t2) { return std::max(t1, t2); }
    static T min(const T &t1, const T &t2) { return std::min(t1, t2); }
    static T gcd(const T &t1, const T &t2) { return std::gcd(t1, t2); }

   public:
    sparseTable(const std::vector<T> &v, auto func) {
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
    T operator()(int l, int r) const {
        int q = std::__lg(r - l + 1);
        return _func(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};
class RMQ_2 {
    template <class T>
    using G = std::vector<std::vector<T>>;

   private:
    int n, m;
    std::vector<int> pre;
    std::function<int(const int, const int)> _func;
    static int default_func(const int t1, const int t2) {
        return std::max(t1, t2);
    }

    G<G<int>> tmp;
    void init(const G<int> &a) {
        // 二维RMQ
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) tmp[0][0][i][j] = a[i][j];
        pre[2] = pre[3] = 1;
        for (int i = 4, up = _func(n, m); i <= up; i++)
            pre[i] = pre[i >> 1] + 1;
        int up1 = pre[n] + 1, up2 = pre[m] + 1;
        for (int l1 = 0; l1 <= up1; l1++) {
            for (int l2 = 0; l2 <= up2; l2++) {
                if (!l1 && !l2) continue;
                for (int i = 1; (i + (1 << l1) - 1) <= n; i++) {
                    for (int j = 1; (j + (1 << l2) - 1) <= m; j++) {
                        if (l2)
                            tmp[l1][l2][i][j] =
                                _func(tmp[l1][l2 - 1][i][j],
                                      tmp[l1][l2 - 1][i][j + (1 << (l2 - 1))]);
                        else
                            tmp[l1][l2][i][j] =
                                _func(tmp[l1 - 1][l2][i][j],
                                      tmp[l1 - 1][l2][i + (1 << (l1 - 1))][j]);
                    }
                }
            }
        }
    }

   public:
    RMQ_2(const std::vector<std::vector<int>> &a, auto func = default_func) {
        _func = func;
        n = a.size() - 1;
        m = a[0].size() - 1;
        int lg = std::__lg(std::max(n, m)) + 1;
        pre.resize(n + 1);
        tmp.resize(lg, std::vector<G<int>>(
                           lg, G<int>(n + 1, std::vector<int>(m + 1))));
        init(a);
    }
    int query(int x1, int y1, int x2, int y2) {
        int p = pre[x2 - x1 + 1], q = pre[y2 - y1 + 1];
        int ans = INT_MIN;
        ans = _func(tmp[p][q][x1][y1], tmp[p][q][x1][y2 - (1 << q) + 1]);
        ans =
            _func(ans, _func(tmp[p][q][x2 - (1 << p) + 1][y1],
                             tmp[p][q][x2 - (1 << p) + 1][y2 - (1 << q) + 1]));
        return ans;
    }
};