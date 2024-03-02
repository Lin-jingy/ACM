#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> v(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    std::vector<int> s(n + 1);
    
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        std::cin >> a >> b;
        s[a] ^= 1 << i;
        s[b] ^= 1 << i;
    }
    
    std::vector<std::vector<int>> list(k);
    auto dfs = [&](auto self, int p, int fa) -> void {
        for (auto i : v[p]) {
            if (i == fa) continue;
            self(self, i, p);
            s[p] ^= s[i];
        }
        for (auto i : v[p]) {
            if (i == fa) continue;
            for (int j = 0; j < k; j++) {
                if (~s[p] & s[i] & (1 << j)) {
                    list[j].push_back(s[i]);
                }
            }
        }
    };
    dfs(dfs, 1, 0);
    std::vector<int> dp(1 << k, n);
    dp[0] = 0;
    for (int i = 1; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) {
            for (int L : list[j]) {
                dp[i] = std::min(dp[i], dp[i & ~L] + 1);
            }
        }
    }
    std::cout << dp[(1 << k) - 1] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--)solve();
    return 0;
}