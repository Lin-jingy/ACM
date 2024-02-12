#include<bits/stdc++.h>

using namespace std;
#define int long long 
int a[100005], n;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n / 2; ++i) {
		if(ans == 0)ans = abs(a[n - i + 1] - a[i]);
		else ans = __gcd(ans, abs(a[n - i + 1] - a[i]));
	}
	cout << ans << '\n';
	return;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}