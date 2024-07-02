#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) { 
        std::cin >> a[i];
    }
    std::sort(a.begin() + 1, a.end());
    int ans = 0;
    for(int i = 2; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            ans = std::max(ans, a[n] - a[1] + a[j] - a[1] + a[n] - a[i] + a[j] - a[i]);
        }
    }
    std::cout << ans << '\n';
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
// -1 1 2 2