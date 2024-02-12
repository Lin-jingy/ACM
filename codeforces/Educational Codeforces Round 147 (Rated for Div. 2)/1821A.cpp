#include<bits/stdc++.h>

using namespace std;
#define int long long 

void solve() {
	string a;
	cin >> a;
	int ans = 1;
	int k = 0;
	int len = a.size();
	if (a[0] == '0') {
		cout << 0 << '\n';
		return;
	}
	for (int i = 1; i < len; ++i)if (a[i] == '?')ans *= 10, ++k;
	if (a[0] == '?')ans *= 9, ++k;
	if (k == 0)cout << 1 << '\n';
	else cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}