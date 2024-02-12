#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[105] = { 0 };
		for (int i = 0; i < n; ++i)cin >> a[i];
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 1 && a[i + 1] >= 0) {
				ans++;
				a[i] = 0;
				a[i + 1]--;
				--i;
			}
			else if (a[i] != 0) {
				a[i] = 0;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}