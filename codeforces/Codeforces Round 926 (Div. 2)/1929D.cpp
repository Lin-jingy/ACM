#include <bits/stdc++.h>

#define int long long
constexpr int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> v(n + 1);
    for(int i = 1; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    std::vector<int> dp(n + 1);
    auto dfs = [&](auto &&self, int p, int fa) ->void {
        dp[p] = 1;
        for(auto e:v[p]) {
            if(e == fa) continue;
            self(self, e, p);
            dp[p] = (dp[p] * (dp[e] + 1)) % mod;
        }
    };
    dfs(dfs, 1, 0);
    int ans = 1;
    for(int i = 1; i <= n; ++i) ans = (ans + dp[i]) % mod;
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}