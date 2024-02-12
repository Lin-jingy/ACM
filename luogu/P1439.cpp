//LCS问题
//LIS转化
//把a的数据作为排序的依据对b进行LIS
/*
* a：3 2 1 4 5
* b：1 2 3 4 5
*
*
例如将a转化：  a：a b c d e
			   b：c b a d e

求最大公共子序列问题即可转化为对b数组进行LIS的过程


*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define quick std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
#define int long long
const int MAX = 1e5 + 5;
int dp[MAX];
int b[MAX];
unordered_map<int, int>m;
void solve() {
	int n; cin >> n;
	int x;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		m.insert({ x,i });
	}
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		b[i] = m[x];
	}
	int ans = 0;
	dp[++ans] = b[1];
	for (int i = 2; i <= n; ++i) {
		int it = upper_bound(dp + 1, dp + ans + 1, b[i]) - dp;
		dp[it] = b[i];
		if (it > ans)++ans;
	}
	cout << ans;
	return;
}
signed main() {
	quick;
	int t = 1;
	while (t--)solve();
	return 0;
}