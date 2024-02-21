#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x;
    std::cin >> n >> x;
    if((n + x) % 2 == 0) std::cout << (n + x) / 2 << ' ' << n - (n + x) / 2;
    else std::cout << -1;

    return 0;
}