#include <bits/stdc++.h>

#define int long long
int dp[10005];

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    if(n >= 10000) {
        int num = (n - 1e4 + 14) / 15;
        ans += num;
        n -= num * 15;
    }
    std::cout << ans + dp[n] << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 1; i <= 10000; ++i) dp[i] = INT_MAX;
    
    for(int i = 1; i <= 10000; ++i) {
        dp[i] = dp[i - 1] + 1;
        if(i >= 3) dp[i] = std::min(dp[i], dp[i - 3] + 1);
        if(i >= 6) dp[i] = std::min(dp[i], dp[i - 6] + 1);
        if(i >= 10) dp[i] = std::min(dp[i], dp[i - 10] + 1);
        if(i >= 15) dp[i] = std::min(dp[i], dp[i - 15] + 1);
    }


    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}