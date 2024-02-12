#include<bits/stdc++.h>

//#define int long long
const int mod = 998244353;
std::string s[20];
int dp[19][19][2][1 << 19];

void solve() {
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) std::cin >> s[i], s[i] = ' ' + s[i];
    for(int i = 0; i <= m; ++i) s[0][i] = '1';
    for(int i = 0; i <= n; ++i) s[i][0] = '1';
    long long ans = 0;
    auto fact = [&](int i, int j, int k, int l, int val) ->void {
        if(i == n and j == m) {
            ans = (ans + val) % mod;
            return;
        }
        if(j == m) i++, j = 0, k = 1;
        if(s[i][j + 1] != '1') {
            dp[i][j + 1][0][l & ~(1 << j)] += mod - val;
            if(dp[i][j + 1][0][l & ~(1 << j)] < 0) dp[i][j + 1][0][l & ~(1 << j)] += mod;
        }
        if(s[i][j + 1] != '0' and (k or ((l >> j) & 1))) {
            dp[i][j + 1][k][l] += mod - val;
            if(dp[i][j + 1][k][l] < 0) dp[i][j + 1][k][l] += mod;
        }
        
    };
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            for(int k = 0; k < 2; ++k) {
                for(int l = 0; l < (1 << m); ++l) {
                    fact(i, j, k, l, dp[i][j][k][l]);
                }
            }
        }
    }
    std::cout << ans % mod << '\n';

    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}