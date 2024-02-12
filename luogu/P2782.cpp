//TLE
//O(n^2)

//#include<bits/stdc++.h>
//using namespace std;
//#define quick std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
//#define int long long
//const int MAX = 2e5 + 5;
//int dp[MAX];
//struct ff {
//	int l, r;
//}a[MAX];
//bool fact(ff a, ff b) {
//	return a.r < b.r;
//}
//void solve() {
//	int n; cin >> n;
//	for (int i = 0; i < n; ++i) {
//		cin >> a[i].l >> a[i].r;
//	}
//	sort(a, a + n, fact);
//	int ans = 0;
//	for (int i = 0; i < n; ++i) {
//		dp[i] = 1;
//		for (int j = 0; j < i; ++j) {
//			if (a[i].l > a[j].l)dp[i] = max(dp[i], dp[j] + 1);
//		}
//	}
//	for (int i = 0; i < n; ++i)ans = max(ans, dp[i]);
//	cout << ans << '\n';
//	return;
//}
//signed main() {
//	quick;
//	int t = 1;
//	while (t--)solve();
//	return 0;
//}


#include<bits/stdc++.h>
using namespace std;
#define quick std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
#define int long long
const int MAX = 2e5 + 5;
int dp[MAX];
struct ff {
	int l, r;
}a[MAX];
bool fact(ff a, ff b) {
	return a.l < b.l;
}
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].l >> a[i].r;
	}
	sort(a + 1, a + n + 1, fact);
	int ans = 0;
	dp[++ans] = a[1].r;
	for (int i = 2; i <= n; ++i) {
		int it = upper_bound(dp + 1, dp + ans + 1, a[i].r) - dp;
		dp[it] = a[i].r;
		if (it > ans)++ans;
	}
	cout << ans << '\n';
	return;
}
signed main() {
	quick;
	int t = 1;
	while (t--)solve();
	return 0;
}