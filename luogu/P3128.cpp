#include <bits/stdc++.h>

#define LOCAL 0
#if LOCAL
#define dbg(x...)                  \
    do {                           \
        std::cout << #x << " -> "; \
        err(x);                    \
    } while (0)

void err() {
    std::cout << std::endl
              << std::endl;
}

template <class T, class... Ts>
void err(T arg, Ts... args) {
    std::cout << std::fixed << std::setprecision(10) << arg << ' ';
    err(args...);
}
#else
#define dbg(...)
#endif

using PII = std::pair<int, int>;
using i128 = __int128;
#define All(x) x.begin(), x.end()
#define eb(x) emplace_back(x)
using vec = std::vector<int>;
void solve();

const int N = 5e4 + 5;
std::vector<int> a[N], dep(N);
int f[N][20];

// 第一次dfs求出每个节点的深度
// 并预处理出他们2 ^ k 的祖先
void dfs(int pos, int fa) {
    dep[pos] = dep[fa] + 1;
    f[pos][0] = fa;
    for (int i = 1; i < 20; ++i) f[pos][i] = f[f[pos][i - 1]][i - 1];
    for (auto i : a[pos])
        if (i != fa) dfs(i, pos);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);  // 将u作为较深的节点
    // 将u, v调整到同一深度
    for (int i = 19; i >= 0; i--)
        if (dep[f[u][i]] >= dep[v]) u = f[u][i];
    if (u == v) return u;
    // 倍增求公共祖先的下一位
    for (int i = 19; i >= 0; i--)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        a[u].eb(v);
        a[v].eb(u);
    }
    dfs(1, 0);
    std::vector<int> d(n + 1);
    std::vector<int> ff(n + 1);
    auto dfs = [&](auto dfs, int p, int fa) -> void {
        ff[p] = fa;
        for (auto i : a[p]) {
            if (i == fa) continue;
            dfs(dfs, i, p);
        }
    };
    dfs(dfs, 1, 0);
    while (k--) {
        int u, v;
        std::cin >> u >> v;
        d[u]++, d[v]++;
        int k = lca(u, v);
        d[k]--, d[ff[k]]--;
    }
    std::vector<int> add(n + 1);
    int mx = 0;
    auto dfs1 = [&](auto dfs1, int p, int fa) -> void {
        add[p] += d[p];
        for (auto i : a[p]) {
            if (i == fa) continue;
            dfs1(dfs1, i, p);
            add[p] += add[i];
        }
        mx = std::max(mx, add[p]);
    };
    dfs1(dfs1, 1, 0);
    std::cout << mx << '\n';
}