#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define quick ios::sync_with_stdio(0),cin.tie(0); 
int dp[1005][1005], a[1005][1005];
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> a[i][j];
			dp[i][j] = a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)ans = max(ans, dp[n][i]);
	cout << ans;
	return;
}
signed main() {
	quick;
	solve();
	return 0;
}