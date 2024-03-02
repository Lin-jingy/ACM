#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, k, c;
    std::cin >> n >> k >> c;
    std::vector<std::vector<int>> v(n + 1);
    for(int i = 1; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(c > k) {
        auto dfs = [&](auto &&self, int p, int fa) ->int {
            int dep = 0;
            for(auto i:v[p]) {
                if(i == fa) continue;
                dep = std::max(dep, self(self, i, p)); 
            }
            return dep + 1;
        };
        std::cout << k * (dfs(dfs, 1, 0) - 1) << '\n';
    } else {
        int ans = 0;
        std::vector<int> dp1(n + 1), dp2(n + 1);
        auto dfs = [&](auto dfs, int p, int fa, int l) -> void {
            for (auto i : v[p]) {
                if (i == fa) continue;
                dfs(dfs, i, p, l + 1);
                int t = dp1[i] + 1;
                if (t > dp1[p])
                    dp2[p] = dp1[p], dp1[p] = t;
                else if (t > dp2[p])
                    dp2[p] = t;
            }
            ans = std::max(ans, (dp1[p] + dp2[p]) * k - (l + std::min(dp1[p], dp2[p])) * c);
        };
        dfs(dfs, 1, 0, 0);
        std::cout << ans << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}