#include<bits/stdc++.h>

using namespace std;
#define int unsigned long long
int n, k;
signed main() {
	//ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		if (k % 2 == 1 or k % 2 == 0 and n % 2 == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}