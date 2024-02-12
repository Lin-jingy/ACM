#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e6+10;
const int mx = 40;
const int mod = 998244353;
int sum[N], dp[N], n, s[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++ i)for(int j = i; j <= n; j += i)s[j]++;
    sum[0]=1, dp[0]=1;
    for(int i = 1; i <= n; ++ i) {
        dp[i] = (sum[i - 1] + s[i] - 1) % mod;
        sum[i] = (dp[i] + sum[i - 1]) % mod;
    }
    cout << dp[n];

}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t --)solve();
    return 0;
}
