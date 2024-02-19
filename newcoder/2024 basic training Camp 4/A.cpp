#include <bits/stdc++.h>

void solve() {
    int a, b, k;
    std::cin >> a >> b >> k;
    if(a >= k * b) std::cout << "good\n";
    else std::cout << "bad\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}