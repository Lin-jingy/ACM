#include <bits/stdc++.h>

#define int long long 

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int>dp(2);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        if (x == 0) {
            dp[0] = std::max(dp[0], std::max(dp[0], dp[1]) + y);
        } else {
            dp[1] = std::max(dp[1], dp[0] + y);
        }
    }
    
    std::cout << std::max(dp[0], dp[1]) << "\n";
    return 0;
}
