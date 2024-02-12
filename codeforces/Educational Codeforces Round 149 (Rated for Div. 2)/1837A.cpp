#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int, int>;

void solve() {
	int x, k;
    cin >> x >> k;
	if (x % k == 0) {
		cout << 2 << '\n';
		cout << -k - 1 << ' ' << x + k + 1 << '\n';
	}
	else {
		cout << 1 << '\n' << x << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--)solve();
	return 0;
}