#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		int lena = a.size();
		int lenb = b.size();
		if (a == b) {
			cout << "yes\n" << a << '\n';
			goto A;
		}
		else {
			if (a[0] == b[0]) {
				/*string ans; ans += a[0];
				for (int i = 1; i < lena; ++i) {
					for (int j = 1; j < lenb; ++j) {
						if (a[i] == b[i]) {
							ans += '*'; ans += +a[i]; ans += '*';
							cout << "yes\n" << ans << '\n';
							goto A;
						}
					}
				}*/
				cout << "yes\n" << a[0] << '*' << '\n';
				goto A;
			}
			else if (a[lena - 1] == b[lenb - 1]) {
				cout << "yes\n" << '*' << a[lena - 1] << '\n';
				goto A;
			}
			else {
				for (int i = 0; i < lena - 1; ++i) {
					for (int j = 0; j < lenb - 1; ++j) {
						if (a[i] == b[j] and a[i + 1] == b[j + 1]) {
							cout << "yes\n" << '*' << a[i] << a[i + 1] << '*' << '\n';
							goto A;
						}
					}
				}
			}
			cout << "no\n";
		A:;
		}
	}
	return 0;
}