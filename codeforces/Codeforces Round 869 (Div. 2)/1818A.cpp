#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	string a;
	char flag[105];
	int ans = n;
	for (int i = 1; i <= k; ++i)cin >> flag[i];
	for (int i = 2; i <= n; ++i) {
		cin >> a;
		for (int j = 1; j <= k; ++j) {
			if (a[j - 1] != flag[j]) {
				--ans;
				break;
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}