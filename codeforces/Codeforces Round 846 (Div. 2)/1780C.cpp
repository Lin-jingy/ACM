#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int a[2005] = { 0 }, b[2005] = { 0 };
		priority_queue<int>p;
		int c[2005] = { 0 };
		for (int i = 0; i < n; ++i) { cin >> a[i]; c[a[i]]++; }
		for (int i = 0; i < m; ++i)cin >> b[i];
		sort(b, b + m, greater<>());
		sort(c, c + 2005, greater<>());
		for (int i = 0; i < 2005; ++i) {
			if (c[i])p.push(c[i]);
			else break;
		}
		int ans = 0;
		for (int i = 0; i < m && !p.empty(); ++i) {
			int k = p.top();
			p.pop();
			if (k < b[i]) {
				ans += k;
			}
			else if (k > b[i]) {
				ans += b[i];
				p.push(k - b[i]);
			}
			else {
				ans += k;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}