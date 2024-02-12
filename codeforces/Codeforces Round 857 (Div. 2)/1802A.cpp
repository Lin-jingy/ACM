#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin >> n;
	int f1 = 0, f0 = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x > 0)f1++;
		else f0++;
	}
	int ans = 0;
	for (int i = 1; i <= f1; ++i) {
		cout << i << ' ';
		ans = i;
	}
	for (int j = 1; j <= f0; ++j) {
		ans--;
		cout << max(0, ans) << ' ';
	}
	cout << '\n';
	ans = 0;
	while (1) {
		if (f1 > 0 and f0 > 0) {
			if (ans == 0) {
				ans++;
				cout << ans << ' ';
				f1--;
			}
			else if (ans == 1) {
				--ans;
				cout << ans << ' ';
				f0--;
			}
		}
		else if (f1 == 0 and f0 != 0) {
			cout << "0 ";
			f0--;
		}
		else if (f0 == 0 and f1 != 0) {
			f1--;
			ans++;
			cout << ans << ' ';
		}
		else if (f1 <= 0 and f0 <= 0)break;
	}
	cout << '\n';
	return;
}
signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}