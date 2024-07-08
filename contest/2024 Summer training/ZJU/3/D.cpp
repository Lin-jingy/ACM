#include<bits/stdc++.h>

#define int long long
constexpr int N = 52;
int a[N];
int nn, m1, m2;
int list[N];
int ans = LLONG_MAX;
int dp[N + 4];
void dfs(int last, int n, int t) {
    if (n == 0) {
        list[nn] = last;
        if(last < t) return ;
        memset(dp, -1, sizeof(dp));
        int mx = 0;
        dp[0] = 0;
        for (int i = 1; i <= nn; ++i) {
            for (int j = m1; j >= 0; --j) {
                dp[j] = dp[j];
                if (j >= list[i] and dp[j - list[i]] != -1)
                    dp[j] = std::max(dp[j - list[i]] + a[i], dp[j]);
            }
        }
        for (int i = 0; i <= nn; ++i) mx = std::max(mx, dp[i]);
        ans = std::min(ans, mx);
        return;
    }
    for (int i = t; i <= last and (n - 1) * i <= last; ++i) {
        list[nn - n + 1] = i;
        dfs(last - i, n - 1, i);
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> nn >> m1 >> m2;
    for (int i = 1; i <= nn; ++i) std::cin >> a[i];
    std::sort(a + 1, a + 1 + nn);
    dfs(m2, nn, 0);
    // dfs(50, 50, 0);
    std::cout << ans << '\n';

    return 0;
}