#include <bits/stdc++.h>

constexpr int N = 1e3 + 5;
int dp[N][N];
int lose[N], win[N], use[N];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x;
    std::cin >> n >> x;

    for(int i = 1; i <= n; ++i) {
        std::cin >> lose[i] >> win[i] >> use[i];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = x; j >= 0; --j) {
            dp[i][j] = dp[i - 1][j] + lose[i];
            if(j + use[i] <= x) dp[i][j] = std::max(dp[i][j], dp[i - 1][j + use[i]] + win[i]);
        }
    }
    int mx = 0;
    for(int i = 0; i <= x; ++i) mx = std::max(mx, dp[n][i]);
    std::cout << 5LL * mx << '\n';
    return 0;
}