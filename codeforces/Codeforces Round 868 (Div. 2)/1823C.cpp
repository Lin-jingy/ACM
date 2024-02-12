#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
#define int long long
unordered_map<int, int>mp;

void so(int x) {
	for (int i = 2; i * i <= x; ++i) {
		while (x % i == 0) {
			mp[i] ++;
			x /= i;
		}
	}
	if (x != 1)mp[x] ++;
}

void solve() {
    int n;
	cin >> n;
	mp.clear();
	int x;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		so(x);
	}
	int sum = 0;
    int kt = 0;
	for (auto i : mp) sum += i.second / 2, kt += i.second % 2;
	cout << sum + (kt / 3) << '\n';
	//cout << ((int)v.size() - 1) / 2 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}