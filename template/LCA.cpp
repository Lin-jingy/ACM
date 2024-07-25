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
    std::function<T(const T, const T)> _func;
public:
    void init(const std::vector<T> &v, auto func) {
        _func = func;
        int len = v.size();
        int L1 = std::__lg(len) + 1;
        ST.assign(len, std::vector<T>(L1));
        for(int i = 0; i < len; ++i) ST[i][0] = v[i];

        for(int j = 1; j < L1; ++j) {
            int pj = (1 << (j - 1));
            for(int i = 0; i + pj < len; ++i) {
                ST[i][j] = func(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    sparseTable() = default;
    T operator() (int l, int r) {
        int q = std::__lg(r - l + 1);
        return _func(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};

    std::vector<int> pos, id;
    sparseTable<int> ST;
public:
    eular_LCA(std::vector<std::vector<int>> &v, int root) {
        int len = v.size();
        pos.resize(len);
        id.resize(len);
        std::vector<int> dfn;
        int cnt = -1;
        auto dfs = [&](auto self, int p, int fa)->void {
            ++cnt;
            id[cnt] = p;
            dfn.push_back(cnt);
            pos[p] = dfn.size() - 1;
            int copy_cnt = cnt;
            for(auto i:v[p]) {
                if(i == fa) continue;
                self(self, i, p);
                dfn.push_back(copy_cnt);
            }
        };
        dfs(dfs, root, 0);
        ST.init(dfn, [](const int a, const int b) {
            return std::min(a, b);
        });
    }
    int lca(int a, int b) {
        int x = pos[a], y = pos[b];
        if(x > y) std::swap(x, y);
        return id[ST(x, y)];
    }
};