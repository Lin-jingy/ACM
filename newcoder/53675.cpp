#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define quick ios::sync_with_stdio(0),cin.tie(0); 
const int mod = 2333;
const int N = 3e3 + 5;
int a[N][N], dp[N][N];
void solve() {
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    dp[m][1] = 1;
    for (int i = m; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] != 1) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j] + dp[i][j - 1]);
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[1][n];
    return;
}
signed main() {
    quick;
    solve();
    return 0;
}