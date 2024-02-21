#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x;
    std::cin >> n;
    int ans = n;
    for(int i = 1; i <= n; ++i) {
        std::cin >> x;
        if(x == 1) ans --;
    }
    std::cout << n << '\n';

    return 0;
}