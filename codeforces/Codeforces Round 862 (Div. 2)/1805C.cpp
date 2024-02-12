#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
void solve() {
	int n, m; cin >> n >> m;
	int x;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= m; ++i) {
		int aa, b, c;
		cin >> aa >> b >> c;
		if (c <= 0) {
			cout << "NO\n";
			continue;
		}
		/*if (a[n]> b - 2 * sqrt(aa * c) and a[n] < b + 2 * sqrt(aa * c)) {
			cout << "YES\n";
			cout << a[n] << '\n';
		}
		else if (a[1] < b + 2 * sqrt(aa * c) and a[1]> b - 2 * sqrt(aa * c)) {
			cout << "YES\n";
			cout << a[1] << '\n';
		}*/
		double k1 = b - sqrt(aa * c) * 2;
		double k2 = b + 2 * sqrt(aa * c);
		/*if ((a[1] - b) * (a[1] - b) - 4 * aa * c < 0) {
			cout << "YES\n" << a[1] << '\n';
		}
		else if ((a[n] - b) * (a[n] - b) - 4 * aa * c < 0) {
			cout << "YES\n" << a[n] << '\n';
		}
		else cout << "NO\n";*/
		int l = 1, r = n;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid] > k1 and a[mid] < k2) {
				ans = mid;
				break;
			}
			if (a[mid] <= k1) {
				l = mid + 1;
			}
			if (a[mid] >= k2)r = mid - 1;
		}
		if (ans >= 1 and ans <= n) {
			cout << "YES\n";
			cout << a[ans] << '\n';
		}
		else {
			cout << "NO\n";
		}
	}
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}