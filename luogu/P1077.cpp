#include <bits/stdc++.h>

#define int long long
constexpr int mod = 1e6 + 7;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    std::vector<int> a(N + 1);
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1));
    for(int i = 1; i <= N; ++i) std::cin >> a[i];

    dp[0][0] = 1;
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j <= a[i]; ++j) {
            for(int k = j; k <= M; ++k) {
                dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % mod;
            }
        }
    }
    std::cout << dp[N][M];
    return 0;
}