#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    if(k == 4 * n - 2) std::cout << 2 * n << '\n';
    else std::cout << (k + 1) / 2 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}