#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define int long long
#define mod 998244353
int l, r;
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		cin >> l >> r;
		int sum = 1;
		int x = 1;
		for (int i = l * 2; i <= r; i *= 2) ++sum, x *= 2;
		int add = (r / (x / 2 * 3)) - (l - 1);
		if (add < 0)add = 0;
		int ans = (r / x) - (l - 1) + add * (sum - 1);
		cout <<sum<<' '<< ans << '\n';
	}
	return 0;
}