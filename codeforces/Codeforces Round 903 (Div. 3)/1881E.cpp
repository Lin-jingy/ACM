#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<std::array<int, 2>> dp(n + 10, {INT_MAX, INT_MAX});
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = std::min(dp[i][0], dp[i - 1][0] + 1);
        if(i + a[i] <= n) {
            dp[i][1] = std::min(dp[i][1], dp[i - 1][0]);
            dp[i + a[i] + 1][0] = std::min(dp[i + a[i] + 1][0], dp[i][1] + 1);
            dp[i + a[i] + 1][1] = std::min(dp[i + a[i] + 1][1], dp[i][1]);
        }
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; ++i) ans = std::min(ans, dp[i][0] + n - i);
    std::cout << std::min(ans, dp[n + 1][1]) << '\n';

}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
