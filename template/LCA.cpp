#include <bits/stdc++.h>


class multi_LCA {
private:
    std::vector<int> dep;
    std::vector<std::array<int, 20>> f;
    void dfs(int pos, int fa, std::vector<std::vector<int>> &v) {
        dep[pos] = dep[fa] + 1, f[pos][0] = fa;
        for (int i = 1; i < 20; ++i) f[pos][i] = f[f[pos][i - 1]][i - 1];
        for (auto i : v[pos]) if (i != fa) dfs(i, pos, v);
    }
public:
    multi_LCA(int n, std::vector<std::vector<int>> &v):dep(n+1),f(n+1){dfs(1, 0, v);}
    int lca(int u, int v) {
        if (dep[u] < dep[v]) std::swap(u, v);
        for (int i = 19; i >= 0; i--) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
        if (u == v) return u;
        for (int i = 19; i >= 0; i--) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
        return f[u][0];
    }
};


class eular_LCA {
private:
    template <class T>
    class sparseTable {
    private:
        std::vector<std::vector<T>> ST;
        using func = std::function<T(const T&, const T&)>;
        func _func;
    public:
        sparseTable() = default;
        void init(const std::vector<T> &v, auto func) {
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
        T query(int l, int r) {
            int q = std::__lg(r - l + 1) - 1;
            return _func(ST[l][q], ST[r - (1 << q) + 1][q]);
        }
    };

    std::vector<int> pos;
    sparseTable<int> ST;
public:
    eular_LCA(std::vector<std::vector<int>> &v) {
        int len = v.size();
        pos.assign(len, {});
        std::vector<int> dfn;
        auto dfs = [&](auto self, int p)->void {
            dfn.push_back(p);
            pos[p] = dfn.size() - 1;
            for(auto i:v[p]) {
                self(self, i);
                dfn.push_back(p);
            }
        };
        dfs(dfs, 1);
        ST.init(dfn, [](const int a, const int b) {
            return std::min(a, b);
        });
    }
    int lca(int a, int b) {
        int x = pos[a], y = pos[b];
        if(x > y) std::swap(x, y);
        return ST.query(x, y);
    }
};
