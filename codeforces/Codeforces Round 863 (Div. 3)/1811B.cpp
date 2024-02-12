#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
void solve() {
	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	x1 = min(x1, n - x1 + 1);
	x2 = min(x2, n - x2 + 1);
	y1 = min(y1, n - y1 + 1);
	y2 = min(y2, n - y2 + 1);
	//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << "\n";
	x1 = n / 2 - x1 + 1;
	x2 = n / 2 - x2 + 1;
	y1 = n / 2 + 1 - y1;
	y2 = n / 2 + 1 - y2;
	//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << "\n\n";
	cout << abs(max(x1, y1) - max(x2, y2)) << '\n';
 
}
 
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}