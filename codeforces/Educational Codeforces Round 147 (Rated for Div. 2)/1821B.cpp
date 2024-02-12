#include<bits/stdc++.h>

using namespace std;
#define int long long 
int a[200005], b[200005];

void solve() {
	int n;
	cin >> n;
	int l = n, r = 1;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		if (a[i] != b[i])l = min(l, i), r = max(r, i);
	}
	while (l > 1 and b[l - 1] <= b[l])--l;
	while (r < n and b[r + 1] >= b[r])++r;
	cout << l << ' ' << r << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}