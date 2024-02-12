#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int, int>;

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int a[N], b[N], p[N];

void solve() {
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n; ++i)cin >> b[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	int flag = 0;
	for (int i = 1; i <= n; ++i) {
		int k = 0;
		for (int j = flag + 1; j <= n; ++j) {
			if (a[i] > b[j])flag = j;
			else break;
		}
		k = flag - i + 1;
		if (k == 0) {
			cout << 0 << '\n';
			return;
		}
		ans = ans * k % mod;
	}
	cout << ans % mod << '\n';
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--)solve();
	return 0;
}
