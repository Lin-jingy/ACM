#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int gcd(int a, int b) {
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
signed main() {
	std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 0;
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; ++i) { cin >> a[i]; sum2 += a[i]; }
		sum1 = a[0]; sum2 -= a[0];
		ans = gcd(sum1, sum2);
		for (int i = 1; i < n - 1; ++i) {
			sum1 += a[i]; sum2 -= a[i];
			ans = max(ans, gcd(sum1, sum2));
		}
		cout << ans << '\n';
	}
	return 0;
}