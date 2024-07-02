#include <bits/stdc++.h>

#define int long long

constexpr int N = 1e6 + 1;
int f[N], dp[N], a[N];

void solve() {
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int ans = 0, mn = INT_MAX;
    std::fill(f, f + N, INT_MAX);
    for(int i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        f[a[i]] = std::min(a[i] - b, f[a[i]]);
        mn = std::min(a[i] - b, mn);
    }

    for(int i = 1; i < N; ++i) f[i] = std::min(f[i - 1], f[i]);
    for(int i = 1; i < N; ++i) {
        if(i >= f[i]) dp[i] = dp[i - f[i]] + 2;
    }
    // for(int i = 1; i < 22; ++i) std::cout << i << ' ' << dp[i] << '\n';

    for(int i = 1; i <= m; ++i) {
        int c;
        std::cin >> c;
        if(c > 1e6) {
            int num = (c - 1e6 + mn - 1) / mn;
            ans += num * 2;
            c -= num * mn;
        }
        ans += dp[c];
    }

    std::cout << ans << '\n';

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}