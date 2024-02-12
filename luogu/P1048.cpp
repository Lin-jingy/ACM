#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define quick ios::sync_with_stdio(0),cin.tie(0); 
const int N = 1005;
int times[N], value[N];
int dp[N];//第一个维度是第i株，第二个维度是所用时间，值为获得价值的最大值

/*
转移方程
选择不采这一株   dp[i] = dp[i-1];
选择采这一株     dp[i] = dp[i-times[i]]+value[i];
*/
void solve() {
	int t, m; cin >> t >> m;
	for (int i = 1; i <= m; ++i)cin >> times[i] >> value[i];
	for (int i = 1; i <= m; ++i) {
		for (int j = t; j >= 0; --j) {
			if (j >= times[i])dp[j] = max(dp[j], dp[j - times[i]] + value[i]);
			else dp[j] = max(dp[j], dp[j - 1]);
		}
	}
	cout << dp[t];




	return;
}
signed main() {
	quick;
	solve();
	return 0;
}