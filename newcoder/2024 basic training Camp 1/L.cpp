#include <bits/stdc++.h>

void solve() {
    int c, d, h, w;
    std::cin >> c >> d >> h >> w;
    std::cout << 3 * w * c << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
