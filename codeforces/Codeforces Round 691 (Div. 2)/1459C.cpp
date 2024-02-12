#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 2e5 + 5;
int a[N], b[N];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)cin >> a[i];
    for(int i = 1; i <= m; ++i)cin >> b[i];
    int ans = abs(a[1] - a[n]);
    for(int i = 2; i < n; ++i) ans = __gcd(ans, abs(a[i] - a[n]));
    for(int i = 1; i <= m; ++i)cout << __gcd(ans, abs(a[n] + b[i])) << ' ';

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
