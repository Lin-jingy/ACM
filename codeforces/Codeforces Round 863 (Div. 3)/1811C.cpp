#include<bits/stdc++.h>
 
using namespace std;
#define int long long
int a[200005];
int b[200005];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n + 2; ++i)a[i] = 0, b[i] = 0;
	for (int i = 1; i < n; ++i) cin >> a[i];
	b[1] = a[1];
	for (int i = 2; i < n; ++i) {
		if (a[i] > a[i - 1])b[i] = a[i - 1];
		else b[i] = a[i];
	}
	b[n] = a[n - 1];
	for (int i = 1; i <= n; ++i)cout << b[i] << " \n"[i == n];
}
 
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}
