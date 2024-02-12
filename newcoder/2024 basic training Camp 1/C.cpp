#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, q, t;
    std::cin >> n >> q >> t;
    std::vector<int> a(n), pre(n);
    for (auto &i : a) std::cin >> i;
    std::sort(a.begin(), a.end());
    pre[0] = a[0];
    for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i];
    while (q--) {
        int m;
        std::cin >> m;
        int pos = n - m / t - 1;
        if (pos < 0)
            std::cout << t << '\n';
        else
            std::cout << pre[pos] + t << '\n';
    }
}
// 1 3 6 10

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
