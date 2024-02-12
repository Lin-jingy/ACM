#include <bits/stdc++.h>

#define int long long 
const int N = 3e3 + 10;
int a[N], b[N];
int f[N][4];

void solve(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>>dp(n + 1, std::vector<int>(m + 1));
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 1; i <= n; i++) std::cin >> b[i];
    //memset(f, -0x7f, sizeof f);
    for(int i = 0; i < N; ++i) for(int j = 0; j < 4; ++j) f[i][j] = LONG_LONG_MIN;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= std::min(i, m); j++) {
			dp[i][j] = dp[i - 1][j];
			f[i - j][0] = std::max(f[i - j][0], dp[i - 1][j - 1] - b[i] - a[i]);
			f[i - j][1] = std::max(f[i - j][1], dp[i - 1][j - 1] + b[i] - a[i]);
			f[i - j][2] = std::max(f[i - j][2], dp[i - 1][j - 1] - b[i] + a[i]);
			f[i - j][3] = std::max(f[i - j][3], dp[i - 1][j - 1] + b[i] + a[i]);
			dp[i][j] = std::max(dp[i][j], f[i - j][0] + a[i] + b[i]);
			dp[i][j] = std::max(dp[i][j], f[i - j][1] - a[i] + b[i]);
			dp[i][j] = std::max(dp[i][j], f[i - j][2] + a[i] - b[i]);
			dp[i][j] = std::max(dp[i][j], f[i - j][3] - a[i] - b[i]);
		}
	}
	std::cout << dp[n][m] << '\n';

}

signed main() {
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}