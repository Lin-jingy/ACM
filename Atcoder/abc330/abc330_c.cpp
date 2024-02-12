#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::vector<int> a;
    a.push_back(0);
    for(int i = 1; i * i <= 2e12; ++i) {
        a.push_back(i * i);
    }
    
    int k;
    std::cin >> k;
    int ans = LONG_LONG_MAX;
    int sq = sqrt(k);
    if(sq * sq == k) {
        std::cout << 0 << '\n';
        return 0;
    }
    for(int i = 1; i * i <= k; ++i) {
        auto it = std::lower_bound(a.begin(), a.end(), k - i * i);
        if(it != a.end()) ans = std::min(ans, abs(*it + i * i - k));
        if(it != a.begin()) ans = std::min(ans, abs(*(--it) + i * i - k));
    }
    std::cout << ans << '\n';

    return 0;
}
