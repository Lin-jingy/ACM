#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i], pre[i] = pre[i - 1] + a[i];

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, INT_MAX));
    std::vector<std::vector<int>> dp1(n + 1, std::vector<int>(n + 1));

    for(int len = 1; len <= n; ++len) {
        for(int i = 1; i <= n - len + 1; ++i) {
            int r = i + len - 1;
            dp[i][i] = 0;
            for(int j = i; j < r; ++j) {
                dp[i][r] = std::min(dp[i][r], dp[i][j] + dp[j + 1][r] + pre[r] - pre[i - 1]);
                dp1[i][r] = std::max(dp1[i][r], dp1[i][j] + dp1[j + 1][r] + pre[r] - pre[i - 1]);
            }
        }
    }
    std::cout << dp[1][n] << '\n' << dp1[1][n] << '\n';
    return 0;
}