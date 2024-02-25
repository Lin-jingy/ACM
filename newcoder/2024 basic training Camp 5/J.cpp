#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int ans = 0;
    int mn = -1e9, mx = 1e9;
    for(int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        if(std::max(l, mn) <= std::min(r, mx)) {
            mn = std::max(mn, l);
            mx = std::min(mx, r);
        }else {
            if(r < mn) ans += mn - r, mn = mx = r;
            if(l > mx) ans += l - mx, mn = mx = l;
        }
    }
    std::cout << ans << '\n';

    return 0;
}