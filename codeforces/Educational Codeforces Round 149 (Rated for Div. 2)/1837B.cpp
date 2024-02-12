#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int, int>;
int k1, k2, ans;
int n;
string a;

void solve() {
	cin >> n >> a;
	k1 = 0, ans = 0, k2 = 0;
	for (auto i:a) {
		if (i == '<')++k1;
		else k1 = 0;
        if(i == '>')++k2;
        else k2 = 0;
		ans = max(ans, max(k1, k2));
	}
	cout << ans + 1 << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--)solve();
	return 0;
}