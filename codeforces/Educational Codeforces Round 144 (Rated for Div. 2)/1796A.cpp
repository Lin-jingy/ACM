#include<bits/stdc++.h>
using namespace std;
#define int long long 
string s = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string a;
		cin >> a;
		for (int i = 0; i < 33 - n + 1; ++i) {
			string mid;
			for (int j = 0; j < n; ++j)mid += s[i + j];
			if (mid == a) { cout << "yes\n"; goto A; }
		}
		cout << "no\n";
	A:;
	}
	return 0;
}