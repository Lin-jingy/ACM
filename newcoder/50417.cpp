#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define quick ios::sync_with_stdio(0),cin.tie(0); 
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int dp[N][2];
void solve() {
    int n; cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = dp[i - 1][0] % mod;


    }
    cout << (dp[n][1] + dp[n][0]) % mod;
    return;
}
signed main() {
    quick;
    solve();
    return 0;
}