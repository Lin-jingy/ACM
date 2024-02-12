#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int n;
    cin >> n;
    vector<int>a(n + 1), sum(n + 1);
    for(int i(1); i <= n; ++i) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    int mx(0), ans(0), s(0);
    for(int i(1); i <= n; ++i) {
		mx = max(mx, sum[i]);
		if (ans < mx + sum[n] - sum[i]) ans = mx + sum[n] - sum[i], s = mx;
	}
    cout << s << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
