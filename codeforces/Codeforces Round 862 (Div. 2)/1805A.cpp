#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-')w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
inline void write(int x)
{
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
 
void solve() {
	int a[1005];
	int n;
	cin >> n;
	int flag = 0, ans = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i <= 255; ++i) {
		int k = a[1]^i;
		for (int j = 2; j <= n; ++j) {
			k ^= (a[j] ^ i);
		}
		if (k == 0) {
			cout << i << '\n';
			return;
		}
	}
	cout << "-1\n";
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}