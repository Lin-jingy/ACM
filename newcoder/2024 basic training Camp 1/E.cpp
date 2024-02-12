#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> v[i];
    std::vector<std::pair<int, int>> b(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        b[i] = {x, y};
    }
    int mn = n;
    auto dfs = [&](auto &&dfs, int pos) -> void {
        if (pos == m) {
            int k = 1;
            for (int i = 2; i <= n; ++i) {
                if (v[i] > v[1]) ++k;
            }
            mn = std::min(mn, k);
            return;
        }
        int x = b[pos].first;
        int y = b[pos].second;
        v[x] += 3;
        dfs(dfs, pos + 1);
        v[x] -= 3;
        v[x]++, v[y]++;
        dfs(dfs, pos + 1);
        v[x]--, v[y]--;
        v[y] += 3;
        dfs(dfs, pos + 1);
        v[y] -= 3;
    };
    dfs(dfs, 0);
    std::cout << mn << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
