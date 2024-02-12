#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
	int n, m; cin >> n >> m;
	cout << n * m << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << (i << 10) + j << " "[j == m];
		}
		cout << '\n';
	}
	return;
}
signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}