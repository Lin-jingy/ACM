#include<bits/stdc++.h>

using namespace std;

int change(int x) {
	int sum = 0;
	while (x) {
		++sum;
		x /= 2;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int s[27], mx[27];
		int mn = INT_MAX;
		bool f = 0;
		for (int i = 0; i < 27; ++i)s[i] = 0, mx[i] = 0;
		string a;
		cin >> a;
		int len = a.size();
		a = '0' + a;
		for (int i = 1; i <= len; ++i) {
			int k = a[i] - 'a';
			if (s[k] == 0)s[k] = i, mx[k] = max(mx[k], i - 1);
			else mx[k] = max(mx[k], i - s[k] - 1), s[k] = i;
		}
		for (int i = 0; i < 26; ++i)mx[i] = max(mx[i], len - s[i]), mn = min(mn, mx[i]), f = 1;
		//for (int i = 0; i < 26; ++i) mn = min(mn, mx[i]), flag = 1;
		if (f == 0) cout << change(len) - 1 << '\n';
		else cout << change(mn) << '\n';
	}
	return 0;
}