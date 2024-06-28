#include <bits/stdc++.h>

void solve() {
    int x, y;
    std::cin >> x >> y;
    if(y >= -1) std::cout << "YES\n";
    else std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}