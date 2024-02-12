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
 
void solve() {
	int n, d;
	cin >> n >> d;
 
	string a;
	cin >> a;
	int flag = n;
	for (int i = 0; i < n; ++i) {
		if (a[i] - '0' < d) {
			flag = i;
			break;
		}
	}
	for (int i = 0; i < flag; ++i) {
		cout << a[i];
	}
	cout << d;
	for (int i = flag; i < n; ++i) {
		cout << a[i];
	}
	cout << '\n';
}
 
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}
