#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];

    std::sort(a.begin() + 1, a.end());

    int sum = x + y;
    std::vector<int> dp(sum + 1);

    for(int i = 1; i <= n; ++i) {
        auto last = dp;
        for(int j = 0, p = 0; j <= sum; ++j) {
            auto check = [&]()->bool {
                if(j + p >= sum) return 0;
                return last[j - p] + a[i] > dp[j + p + 1];
            };
            if(p and !check()) --p;
            if(check()) ++p;
            dp[j] = std::max(dp[j], last[j + p]);
            if(p <= j) dp[j] = std::max(dp[j], last[j - p] + a[i]);
        }
    }

    std::cout << dp[x] << '\n';

    return 0;
}