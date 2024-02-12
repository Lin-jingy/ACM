#include <iostream>
#include <vector>

#define int long long

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n), w(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) std::cin >> v[i] >> w[i];
    auto check = [&](int x) -> void {
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if ((w[i] & x) == w[i]) k += v[i];
        }
        ans = std::max(ans, k);
    };
    for (int i = 31; i >= 0; --i) {
        if ((m >> i & 1) == 0) continue;
        check(m ^ (1 << i) | ((1 << i) - 1));
    }
    check(m);
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
