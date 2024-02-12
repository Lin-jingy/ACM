#include <bits/stdc++.h>

using namespace std;
#define int long long 


signed main() {
	int t; cin >> t;
	while (t--) {
		int mx = 0;
		int xx = 0;
		int f = 0;
		int at = 0;
		string a;
		cin >> a;
		if (a.size() == 1) {
			if (a[0] == '1')cout << 1 << '\n';
			else cout << 0 << '\n';
			goto A;
		}
		else {
			int sss = a.size();
			int kk = 0;
			for (int i = 0; i < sss; ++i) {
				if (a[i] != '1')break;
				kk++;
			}
			for (int i = 1; i <= kk; ++i)a += '1';
			for (int i = 1 + kk; i < a.size(); ++i) {
				if (a[i] == '1')f = 1;
				if (a[i] == a[i - 1] and a[i] == '1' and a[i - 1] == '1')++xx;
				else mx = max(mx, xx), xx = 0;
			}
			mx = max(mx,xx);
			mx++;
			if (mx == sss) {
				cout << mx * mx << '\n';
				goto A;
			}
			if (f) {
				if (mx <= 1)cout << 1 << '\n';
				else {
					if (mx % 2 == 1)cout << ((mx / 2 + 1) * (mx / 2 + 1)) << '\n';
					else cout << (mx / 2 * (mx / 2 + 1)) << '\n';
				}
			}else cout << 0 << '\n';
		}
		
	A:;
	}
	return 0;
}