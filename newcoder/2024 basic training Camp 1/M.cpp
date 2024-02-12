#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    if (n % 6 == 0)
        std::cout << n / 6 << '\n';
    else
        std::cout << n / 6 * 2 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
