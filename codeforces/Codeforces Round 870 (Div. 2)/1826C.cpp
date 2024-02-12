#include<bits/stdc++.h>

using namespace std;
#define int long long 

int fact(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return i;
		}
	}
	return x;
}

void solve() {
	int n, m;
	cin >> n >> m;
	if (n == 1 or m == 1) { cout << "YES\n"; return; }
	if (m >= n) { cout << "NO\n"; return; }
	if (n % 2 == 0)cout << "NO\n";
	else {
		int x = fact(n);
		if (x > m)cout << "YES\n";
		else cout << "NO\n";
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--)solve();
	return 0;
}