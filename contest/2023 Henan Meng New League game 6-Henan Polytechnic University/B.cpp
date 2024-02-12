#include<bits/stdc++.h>

#define int long long 

const int N = 310;
__int128 dp[2 * N][2 * N];
int a[N][2 * N + 1];
__int128 mid[2 * N][2 * N];

signed main(){
    int n, sk;
    std::cin >> n >> sk;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= 2 * i - 1; ++j) std::cin >> a[i][j];

    for(int j = 1; j <= 2 * n - 1; ++j)for(int k = 0; k <= 2 * n; ++k) dp[j][k] = LONG_LONG_MIN;
    dp[1][n] = a[1][1];

    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= 2 * i - 1; ++j)for(int k = 0; k <= 2 * n; ++k) mid[j][k] = dp[j][k], dp[j][k] = LONG_LONG_MIN;
        for(int j = 1; j <= 2 * i - 1; ++j){
            for(int k = 0; k <= 2 * n; ++k){
                if(k != 0)dp[j][k-1] = std::max(mid[j][k] + a[i+1][j], dp[j][k-1]);
                dp[j+1][k] = std::max(mid[j][k] + a[i+1][j+1], dp[j+1][k]);
                if(k != 2 * n) dp[j+2][k+1] = std::max(mid[j][k] + a[i+1][j+2], dp[j+2][k+1]);
            }
        }
    }

    __int128 mx = LONG_LONG_MIN;
    for(int i = 1; i <= 2 * n - 1; ++i){
        for(int j = n - sk; j <= n + sk; ++j){
            mx = std::max(mx, dp[i][j]);
        }
    }
    std::cout << (int)mx << '\n';

    return 0;
}