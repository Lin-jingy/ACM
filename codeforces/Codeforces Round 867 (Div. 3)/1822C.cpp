#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::cout << 1LL * n * n + 2 * n + 2 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}