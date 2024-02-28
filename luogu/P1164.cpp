#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    std::vector<int> a(N), dp(M + 1);
    for(int i = 0; i < N; ++i) std::cin >> a[i];

    dp[0] = 1;
    for(int i = 0; i < N; ++i) {
        for(int j = M; j >= a[i]; --j) dp[j] += dp[j - a[i]];
    }
    std::cout << dp[M] << '\n';

    return 0;
}