#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t; cin >> t;
	while (t--) {
		int a1, a2, a3, a4;
		cin >> a1 >> a2 >> a3 >> a4;
		if (a1 == 0) { cout << "1\n"; continue; }
		unsigned int time = a1;
		if (a2 < a3)swap(a2, a3);
		int kt = a2 - a3 + a4;
		time += a3 * 2;
		if (kt > a1)time += a1 + 1;
		else time += kt;
		cout << time << '\n';
	}
	return 0;
}