#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
 
	int n; cin >> n;
	string a;
	cin >> a;
	int mn =0;
	for (int i = 1; i < n; ++i) {
		if (a[i] <= a[mn])mn = i;
	}
	char k=a[mn];
	a.erase(mn,1);
	a = k + a;
	cout << a << '\n';
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}