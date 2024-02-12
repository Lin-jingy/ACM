#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
#define int long long
int a[105];


signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) { cout << 1 << '\n'; continue; }
		if (n & 1) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 0; i < n; ++i) a[i] = i + 1;
		for (int i = 0; i < n; i += 2) swap(a[i], a[i + 1]);
		for (int i = 0; i < n; ++i)cout << a[i] << ' ';
		cout << '\n';
	}
	return 0;
}