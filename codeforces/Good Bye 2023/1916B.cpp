#include <bits/stdc++.h>

#define int long long

void solve() {
    int a, b;
    std::cin >> a >> b;
    if (b % a == 0) std::cout << b / a * b << '\n';
    else std::cout << std::lcm(a, b) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
