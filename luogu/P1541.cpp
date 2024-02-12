//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

int dp[45][45][45][45];

void solve(){
    int n, m, x;
    cin >> n >> m;
    vector<int>a(n + 1), p(5);
    for(size_t i(1); i <= n; ++i) cin >> a[i];
    for(size_t i(1); i <= m; ++i) cin >> x, p[x]++;
    int ans(0);
    dp[0][0][0][0] = a[1]; 
    for(size_t i(0); i <= p[1]; ++i){
        for(size_t j(0); j <= p[2]; ++j){
            for(size_t k(0); k <= p[3]; ++k){
                for(size_t l(0); l <= p[4]; ++l){
                    int pos = i + 2 * j + 3 * k + 4 * l + 1;
                    if(i != 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + a[pos]);
                    if(j != 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + a[pos]);
                    if(k != 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + a[pos]);
                    if(l != 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + a[pos]);
                }
            }
        }
    }
    cout << dp[p[1]][p[2]][p[3]][p[4]] << '\n';
}







// ! TLE
// const int N = 360;
// int a[N], p[5];
// int ans, n, m;

// void dfs (int pos, int k){
//         k += a[pos];
//         if(pos == n) {
//             ans = max(ans, k);
//             return;
//         }
//         for(size_t i = 1; i <= 4; ++i){
//             if(p[i]) p[i]--, dfs(pos + i, k), p[i]++;
//         }
//     }

// void solve(){
//     cin >> n >> m;
//     for(size_t i(1); i <= n; ++i) cin >> a[i];
//     int x;
//     for(size_t i(0); i < m; ++i) cin >> x, p[x]++;
//     dfs(1, 0);
//     cout << ans << '\n';
// }

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
