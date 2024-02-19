#include <bits/stdc++.h>

constexpr int N = 1e3 + 5;
int a[N];
int dp[N][N][4];
std::pair<int, int> mx[N][4];


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        mx[i][3].first = std::max(mx[i][3].first, mx[i - 1][3].first);
        for(int j = 1; j < i; ++j) {
            if(j >= 3) dp[i][j][2] = mx[j - 1][1].second * a[j] - a[i];
            if(j >= 5) dp[i][j][3] = mx[j - 1][2].second * a[j] - a[i];
            dp[i][j][1] = mx[j - 1][3].first + a[j] - a[i];
        }
    }
    
    

    return 0;
}