#include<iostream>
using namespace std;
#define int long long 
signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[300] = { 0 };
		bool pd[300] = { false };//ÅĞ¶ÏÊÇ·ñÎªÆæÊı
		int ji = 0, ou = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			pd[i] = (a[i] % 2);
			pd[i] == 0 ? ++ou : ++ji;
		}
		if (ji >= 3 || (ou >= 2 && ji >= 1))cout << "YES\n";
		else { cout << "NO\n"; continue; }
		if (ji >= 3) {
			int k = 0;
			for (int i = 0; i < n; ++i) {
				if (pd[i] && k < 2) { cout << i + 1 << ' '; ++k; }
				else if (pd[i]) { cout << i + 1 << '\n'; break; }
			}
		}
		else {
			int r0 = 0, r1 = 0, k = 0;
			for (int i = 0; i < n; ++i) {
				if (!pd[i] && k < 2 && r0 < 2) {
					cout << i + 1 << ' ';
					++k; ++r0;
				}
				else if (!pd[i] && r0 < 2 && k == 2) { cout << i + 1 << '\n'; break; }
				else if (pd[i] && k < 2 && r1 < 1) { cout << i + 1 << ' '; ++k; ++r1; }
				else if (pd[i] && k == 2 && r1 < 1) { cout << i + 1 << '\n'; break; }
			}
		}
	}
	return 0;
}