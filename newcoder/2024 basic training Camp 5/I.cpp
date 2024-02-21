#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t, a, k;
    std::cin >> t >> a >> k;
    if(a >= std::min({-k, t - k, t + k, k}) and
       a <= std::max({-k, t - k, t + k, k})) {
        std::cout << abs(a) + std::abs(a - t);
    } else {
        std::cout << std::abs(t) + 2 * std::abs(a - t);
    }
    // if(t < 0) {
    //     t = -t;
    //     a = -a;
    // }
    // if(a >= -k and a <= 0) std::cout << -2 * a + t;
    // else if(a >= 0 and a <= t) std::cout << t;
    // else std::cout << t + 2 * std::abs(a - t);
    return 0;
}