#include<bits/stdc++.h>

int dp[10005][1005];
int a[10005][1005];
int mx[10005];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m, k;
    std::cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) std::cin >> a[i][j];

    for(int j = 1; j <= m; ++j) dp[1][j] = a[1][j], mx[1] = std::max(mx[1], dp[1][j]);
    int ans = mx[1];
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = dp[i - 1][j];
            if(i >= k + 1)dp[i][j] = std::max(dp[i][j], mx[i - k] + a[i][j]);
            mx[i] = std::max(mx[i], dp[i][j]);
        }
        ans = std::max(ans, mx[i]);
    }

    std::cout << ans << '\n';


    return 0;
}