#include <bits/stdc++.h>

double PI = acos(-1);
#define double long double


void solve() {
    int n, l;
    std::cin >> n >> l;
    n *= 2;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    std::vector<double> v(n + 1);
    for(int i = 1; i <= n; ++i) {
        v[i] = (double)a[i] / (2 * l);
    }
    std::sort(v.begin() + 1, v.end());
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(n + 1, 1e18));
    auto calc = [&](int i, int j) ->double {
        return std::abs(sin(v[i] * PI - v[j] * PI)) / 2;
    };
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= i; ++j) dp[i][j] = 0;
    for(int len = 2; len <= n; len += 2) {
        for(int i = 1; i <= n - len + 1; ++i) {
            int r = i + len - 1;
            double val = calc(i, r);
            dp[i][r] = std::min(dp[i][r], dp[i + 1][r - 1] + val);
            for(int j = i + 1; j < r; j += 2) dp[i][r] = std::min(dp[i][r], dp[i][j] + dp[j + 1][r]); 
        }
    }
    printf("%.12Lf\n", dp[1][n]);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}