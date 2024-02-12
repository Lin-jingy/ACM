#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for(auto &i:a) std::cin >> i[0];
    for(auto &i:a) std::cin >> i[1];

    int ans = 0;
    int mn = INT_MAX, mx = 0;
    for(auto [x, y]:a) {
        if(x <= y) {
            mn = std::min(mn, y);
            mx = std::max(mx, x);
        }
    }
    if(mn != INT_MAX and mx != 0) ans = std::max(ans, 2 * (mx - mn));

    mn = INT_MAX, mx = 0;
    for(auto [x, y]:a) {
        if(x <= y) mn = std::min(mn, y);
        if(x >= y) mx = std::max(mx, y);
    }
    if(mn != INT_MAX and mx != 0) ans = std::max(ans, 2 * (mx - mn));

    mn = INT_MAX, mx = 0;
    for(auto [x, y]:a) {
        if(x >= y) {
            mn = std::min(mn, x);
            mx = std::max(mx, y);
        }
    }
    if(mn != INT_MAX and mx != 0) ans = std::max(ans, 2 * (mx - mn));

    mn = INT_MAX, mx = 0;
    for(auto [x, y]:a) {
        if(x >= y) mn = std::min(mn, x);
        if(x <= y) mx = std::max(mx, x);
    }
    if(mn != INT_MAX and mx != 0) ans = std::max(ans, 2 * (mx - mn));

    for(auto [l, r]:a) ans += abs(l - r);
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
