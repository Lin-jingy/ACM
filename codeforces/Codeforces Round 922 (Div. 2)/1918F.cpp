#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    ++k;
    int ans = 2 * n - 2;
    std::vector<std::vector<int>> v(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x;
        std::cin >> x;
        v[x].push_back(i);
    }
    std::vector<int> p;
    auto dfs = [&](auto &&self, int pos, int dep) -> int {
        int r = 0;
        for (auto y : v[pos]) {
            int x = self(self, y, dep + 1) + 1;
            if (x > r) std::swap(x, r);
            p.push_back(x - dep);
        }
        return r;
    };
    p.push_back(dfs(dfs, 1, 0));
    std::ranges::sort(p, std::greater<>());
    while (!p.empty() and p.back() <= 0) p.pop_back();
    for (int i = 0; i < p.size() and i < k; ++i) {
        ans -= p[i];
    }
    std::cout << ans << '\n';
    return 0;
}
