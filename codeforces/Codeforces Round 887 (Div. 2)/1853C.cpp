//#pragma GCC optimize(3)
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

const int N = 2e5 + 5;
int n, k;
int a[N];

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 1;
	int cur = 0;
	while (k--){
		while (cur < n and a[cur + 1] - (cur + 1) < ans) cur++;
		ans += cur;
	}
	cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
