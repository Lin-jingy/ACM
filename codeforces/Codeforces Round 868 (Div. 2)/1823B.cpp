#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[200005];


void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int flag = 0;
	for (int i = 1; i <= k; ++i) {
		for (int j = i; j <= n; j += k) {
			if ((a[j] - i) % k != 0)flag ++;
		}
	}
	if (flag == 0)cout << 0 << '\n';
	else {
		if (flag <= 2)cout << 1 << '\n';
		else cout << -1 << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}