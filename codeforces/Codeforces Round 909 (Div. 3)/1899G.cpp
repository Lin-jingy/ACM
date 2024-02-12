#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n + 1);
    for (int i = 1; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        p[x] = i;
    }
    std::vector<std::vector<std::array<int, 3>>> q(n + 1);
    for (int i = 1; i <= m; ++i) {
        int l, r, pos;
        std::cin >> l >> r >> pos;
        q[pos].emplace_back(std::array<int, 3>{l, r, i});
    }
    std::vector<bool> ans(m + 1);
    std::vector<std::set<int>> sv(n + 1);
    auto dfs = [&](auto dfs, int pos, int f) -> void {
        sv[pos].insert(p[pos]);
        for (auto i : v[pos]) {
            if (i == f) continue;
            dfs(dfs, i, pos);
            if (sv[pos].size() < sv[i].size()) sv[pos].swap(sv[i]);
            //sv[pos].merge(sv[i]);
            sv[pos].insert(sv[i].begin(), sv[i].end());
        }
        for (auto [l, r, i] : q[pos]) {
            auto it = sv[pos].lower_bound(l);
            if (it != sv[pos].end() and *it <= r) ans[i] = 1;
        }
    };
    dfs(dfs, 1, -1);
    for (int i = 1; i <= m; ++i) std::cout << (ans[i] ? "YES\n" : "NO\n");
    //std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
