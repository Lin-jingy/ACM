#include<bits/stdc++.h>

using namespace std;
#define int long long


void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		if (i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2 == k) {
			cout << "YES\n";
			int kk = n - i;
			while (i--)cout << 1 << ' ';
			while (kk--)cout << -1 << ' ';
			cout << '\n';
			return;
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}