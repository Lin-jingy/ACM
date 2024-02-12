#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main() {
	quick;
	int t; cin >> t;
	while (t--) {
		int a[100005] = { 0 };
		int n; cin >> n;
		int ans = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			while (ans<i and a[i - ans]>ans)++ans;
			cout << ans << ' ';
		}
		cout << '\n';
	}
	return 0;
}