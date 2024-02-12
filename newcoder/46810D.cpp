#include <algorithm>
#include <iostream>
#include <vector>

#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n + 1);
    std::vector<int> v(n), d(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x;
        std::cin >> x;
        a[x].push_back(i);
    }
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    std::sort(v.begin(), v.end());
    auto dfs = [&](auto &&dfs, int pos, int fa, int dep) -> void {
        d[pos] = dep;
        for (auto i : a[pos]) {
            if (i == fa) continue;
            dfs(dfs, i, pos, dep + 1);
        }
    };
    dfs(dfs, 1, 0, 1);
    std::sort(d.begin(), d.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += d.back() * v.back();
        d.pop_back(), v.pop_back();
    }
    std::cout << ans << '\n';
}