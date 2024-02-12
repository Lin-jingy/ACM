
#include<bits/stdc++.h>
using namespace std;
#define quick std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
#define int long long
int aa[105][105], p[105][105];
int mins[105][105];
int n, q;
int a[105][105];
bool check(int x) {
	memcpy(a, aa, sizeof(aa));
	int k = x / n;
	int mod = x % n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)continue;
			if (i > mod)a[i][j] = max(a[i][j] - k, p[i][j]);
			else a[i][j] = max(a[i][j] - k - 1, p[i][j]);
			if (j > mod)a[i][j] = max(a[i][j] - k, p[i][j]);
			else a[i][j] = max(a[i][j] - k - 1, p[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (i == j)continue;
				a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
			}
		}
	}
	int sum = 0;
	//cout << x << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			sum += a[i][j];
			/*cout << a[i][j] << ' ';*/
		}
		/*cout << '\n';*/
	}
	//cout << "\n\n";
	if (sum > q)return false;
	return true;
}
void solve() {
	cin >> n >> q;
	int sum = 0;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) { cin >> aa[i][j]; }
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) { cin >> p[i][j]; sum += p[i][j]; }
	/*if (sum > q) { cout << "-1\n"; return; }*/
	int l = 0, r = INT_MAX, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
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