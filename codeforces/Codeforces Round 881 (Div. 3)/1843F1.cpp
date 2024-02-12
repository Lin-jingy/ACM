#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> a[1000005];
int n, x[1000005], maxans[1000005], minans[1000005], u[1000005], v[1000005], w[1000005], m;
inline void dfs(int now, int maxn = 0, int minn = 0) {
	maxn = max(maxn, 0ll);
	minn = min(minn, 0ll);
	maxn += x[now];
	minn += x[now];
	maxn = max(maxn, 0ll);
	minn = min(minn, 0ll);
	maxans[now] = max(maxans[now], maxn);
	minans[now] = min(minans[now], minn);
	for (int i = 0; i < a[now].size(); i++) {
		int v = a[now][i];
		maxans[v] = maxans[now];
		minans[v] = minans[now];
		dfs(v, maxn, minn);
	}
}
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int q;
		cin >> q;
		for (int i = 1; i <= n; i++) {
			x[i] = maxans[i] = minans[i] = 0;
			a[i].clear();
		}
		m = 0;
		n = 1;
		x[1] = 1;
		while (q--) {
			char op;
			cin >> op;
			if (op == '+') {
				int u, data;
				cin >> u >> data;
				x[++n] = data;
				a[u].push_back(n);
			} 
			else {
				m++;
				cin >> u[m] >> v[m] >> w[m];
			}
		}
		dfs(1);
		for (int i = 1; i <= m; i++) {
			if (minans[v[i]] <= w[i] && w[i] <= maxans[v[i]]) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
	return 0;
}