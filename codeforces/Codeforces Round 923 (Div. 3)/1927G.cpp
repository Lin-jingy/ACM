#include <iostream>
#include <vector>

using std::min;
using std::max;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    std::vector dp(n + 2, std::vector<std::vector<int>>(
                              n + 2, std::vector<int>(n + 2, 1e6)));
    
    dp[0][1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            for (int k = 0; k <= n; k++) {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                int l = max(i - a[i] + 1, 1);
                int r = min(i + a[i] - 1, n);
                if (l <= j) {
                    int R = max(i, k);
                    dp[i][R + 1][R] = min(dp[i][R + 1][R], dp[i - 1][j][k] + 1);
                }
                if (j < i) {
                    dp[i][j][max(k, r)] = min(dp[i][j][max(k, r)], dp[i - 1][j][k] + 1);
                } else {
                    int R = max(k, r);
                    dp[i][R + 1][R] = min(dp[i][R + 1][R], dp[i - 1][j][k] + 1);
                }
            }
        }
    }
    std::cout << dp[n][n + 1][n] << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}