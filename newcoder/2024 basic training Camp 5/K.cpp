#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, p;
    std::cin >> n >> p;
    std::vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i];
    int ans = INT_MAX;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, INT_MAX));
    for(int i = 0; i <= n; ++i) dp[i][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1] + p, dp[i][j]});
            dp[i][std::min(j + b[i], n)] = std::min(dp[i][std::min(j + b[i], n)], dp[i][j] + a[i]);
        }
    }
    std::cout << dp[n][n] << '\n';
    return 0;
}