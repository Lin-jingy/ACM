#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string a;
		cin >> a;
		int k = 0;
		if (a.size() == 1) {
			if (a[0] == '_')cout << 2 << '\n';
			else cout << 1 << '\n';
			goto A;
		}
		if (a[0] == '_')++k;
		if (a[a.size() - 1] == '_')++k;
		for (int i = 0; i < a.size() -1; ++i) {
			if (a[i] == a[i + 1] and a[i + 1] == '_' and a[i] == '_')++k;
		}
		cout << k << '\n';
	A:;
	}
	return 0;
}