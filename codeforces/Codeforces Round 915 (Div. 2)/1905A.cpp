#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << std::max(n, m) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}