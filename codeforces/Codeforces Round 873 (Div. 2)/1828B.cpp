#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
 
using namespace std;
#define int long long 
using PII = pair<int, int>;
 
int a[100005], p[100005];
 
void solve() {
	int n;
    cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[a[i]] = i;
	}
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        int k = abs(p[i] - i);
        if (k == 0)continue;
        if(ans != 0)ans = __gcd(ans, k);
        else ans = k;
    }
	cout << ans << '\n';
}
 
signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--)solve();
	return 0;
}