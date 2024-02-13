#include <algorithm>
#include <iostream>
#include <vector>


class DSU {
  private:
    std::vector<int> f, siz;

  public:
    DSU(int n) {
        f.assign(n + 1, {});
        siz.assign(n + 1, {});
        for (int i = 1; i <= n; i++)
            siz[i] = 1, f[i] = i;
    }
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) {
        if (!same(x, y))
            siz[find(y)] += siz[find(x)], f[find(x)] = find(y);
    }
    int qsz(int x) { return siz[find(x)]; }
};

struct node {
    int u, v, w;
    friend bool operator<(node a, node b) { return a.w > b.w; }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    DSU T(n + 1);
    std::vector<node> v(m);
    std::vector<std::vector<int>> a(n + 1);
    for (int i = 0; i < m; ++i)
        std::cin >> v[i].u >> v[i].v >> v[i].w;
    std::sort(v.begin(), v.end());
    int mn, U, V;
    for (auto [u, vv, w] : v) {
        if (T.same(u, vv)) {
            mn = w;
            U = u, V = vv;
        } else {
            T.merge(u, vv);
            a[vv].push_back(u);
            a[u].push_back(vv);
        }
    }
    std::vector<int> ans;
    auto dfs = [&](auto &&self, int pos, int fa) -> bool {
        if (pos == V) {
            ans.push_back(pos);
            return true;
        }
        for (auto i : a[pos]) {
            if(i == fa) continue;
            if(self(self, i, pos)) {
                ans.push_back(pos);
                return true;
            };
        }
        return false;
    };
    dfs(dfs, U, 0);
    std::cout << mn << ' ' << ans.size() << '\n';
    for (auto i : ans) std::cout << i << ' ';
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}