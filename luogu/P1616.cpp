#include <bits/stdc++.h>

#define int long long
using std::vector;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T, M;
    std::cin >> T >> M;
    vector<int> time(M), val(M);
    for(int i = 0; i < M; ++i) std::cin >> time[i] >> val[i];

    vector<int> dp(T + 1);
    for(int i = 0; i < M; ++i) {
        for(int j = time[i]; j <= T; ++j) dp[j] = std::max(dp[j], dp[j - time[i]] + val[i]);
    }
    std::cout << dp[T];
    return 0;
}