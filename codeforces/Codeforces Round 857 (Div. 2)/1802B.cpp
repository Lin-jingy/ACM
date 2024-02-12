#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int ans, int none, int fa, int fb) {
	ans = max(ans, none);
	if (fa > 0 || fb > 0) {
		int kk = (fa - 1) / 2 + (fb - 1) / 2;
		if (fa and fb)ans = max(ans, none + 2 + kk);
		else ans = max(ans, none + 1 + kk);
	}
	return ans;
}
void solve() {
	int n; cin >> n;
	int x;
	int none = 0;
	int fa = 0, fb = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (x == 1) {
			none++;
			ans = max(ans, check(ans, none, fa, fb));
		}
		else if (x == 2) {
			while (none >= 1) {
				--none;
				if (fa < fb and fa % 2 == 1)++fb;
				else if (fa < fb and fa % 2 == 0)++fa;
				else if (fa > fb and fb % 2 == 0)++fb;
				else if (fa > fb and fb % 2 == 1)++fa;
				else ++fa;
			}
			ans = max(ans, check(ans, none, fa, fb));
		}
	}
	cout << ans << '\n';
	return;
}
signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}
}