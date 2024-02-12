#include<bits/stdc++.h>
using namespace std;
#define int long long
//int quickpow(int a, int b) {
//	int sum = 1;
//	while (b) {
//		if (b & 1)
//			sum = sum * a;
//		a = a * a;
//		b >>= 1;
//	}
//	return sum;
//}
//void solve() {
//	int n, m; cin >> n >> m;
//	int k = sqrt(n * m);
//	if (n * m != k * k)++k;
//	int kk = quickpow(2, k)-1;
//	int ans = kk ;
//	cout << n * m << '\n';
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			if (j % 2 == 1)cout << ans-- << ' ';
//			else cout << kk - ans - 1 << ' ';
//		}
//		cout << '\n';
//	}
//	return;
//}
set<int>t1, t2;
void solve() {
	int n; cin >> n;

	int x, y; cin >> x >> y;
	int mx1 = *(--t1.end()), mn1 = *t1.begin();
	int mx2 = *(--t2.end()), mn2 = *t1.begin();
	for (int i = 1; i < n; ++i) {
		cin >> x >> y;
		if (x <= mx1 and x >= mn1);
		else if (y <= mx1 and y >= mn1);
		else if (x > mx1 and y > mx1)x > y ? t1.insert(x) : t1.insert(y);
		else if (x < mn1 and y < mn1)x < y ? t1.insert(y) : t1.insert(x);
		if (x <= mx2 and x >= mn2);
		else if (y <= mx2 and y >= mn2);
		else if (x > mx2 and y > mx2)x > y ? t2.insert(x) : t2.insert(y);
		else if (x < mn2 and y < mn2)x < y ? t2.insert(y) : t2.insert(x);
	}
	if (n >= 3) {
		int k1 = (*++t1.begin()) - *t1.begin();
		int k2 = (*++t2.begin()) - *t2.begin();
		auto it = t1.end();
		--it, --it;
		auto it1 = t2.end();
		--it1, --it1;
		int k3 = *(--t1.end()) - *(it);
		int k4 = *(--t2.end()) - *(it1);
		cout << min(min(k1, k2), min(k3, k4)) << '\n';
	}
	else {
		int k1 = (*++t1.begin()) - *t1.begin();
		int k2 = (*++t2.begin()) - *t2.begin();
		cout << min(k1, k2) << '\n';
	}
	return;
}
signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}