#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n % 2 == 1)cout << "-1\n";
		else cout << "1 " << n / 2 << '\n';
	}
	return 0;
}