#include<bits/stdc++.h>

using namespace std;
#define int long long 
int a[105];

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 0; i <= n; ++i) {
		int f = 0;
		for (int j = 1; j <= n; ++j) {
			if (i < a[j])++f;
		}
		if (f == i) {
			cout << i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
	return;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--)solve();
	return 0;
}