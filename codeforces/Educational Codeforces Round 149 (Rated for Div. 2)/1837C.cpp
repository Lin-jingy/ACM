#include<iostream>
#include<algorithm>

using namespace std;
string a;

signed main() {
	int t = 1;
	cin >> t;
	while (t--) {
		cin >> a;
		int k = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != '?') {
				k = i;
				break;
			}
		}
		for (int j = 0; j < k; ++j)a[j] = a[k];
		k = 0;
		for (int i = a.size() - 1; i >= 0; --i) {
			if (a[i] != '?') {
				k = i;
				break;
			}
		}
		for (int j = a.size(); j > k; --j)a[j] = a[k];
		int f1 = k;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != '?') {
				if (a[i] == a[f1]) {
					for (int j = f1; j < i; ++j)
						if (a[j] == '?')a[j] = a[i];
				}
				else {
					for (int j = f1; j < i; ++j)
						if (a[j] == '?')a[j] = '0';
				}
				f1 = i;
			}
		}
		for (auto& i : a)if (i == '?')i = '1';
		for (auto i : a)cout << i;
		cout << '\n';
	}
	return 0;
}