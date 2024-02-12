#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, s, r;
		cin >> n >> s >> r;
		--n;
		int rr = r;
		for (int i = 1; i <= n; ++i) {
			double k = r * 1.0 / (n - i + 1);
			int ans = 0;
			if ((int)(k + 0.5) == (int)k) ans = k;
			else ans = (int)k + 1;
			r -= ans;
			cout << ans << ' ';
		}
		cout << s - rr << '\n';
	}
	return 0;
}