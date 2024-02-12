#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int, int>;


int a[205];

void solve() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = i;
		sum += i;
	}
	int k = sum / n;
	int ki = (k + 1) * n - sum;
	a[1] += ki;
	for (int i = 1; i <= n; ++i)cout << a[i] << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--)solve();
	return 0;
}


