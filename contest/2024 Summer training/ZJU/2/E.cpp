#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::set<int> set;
    for(int i = 0, x; i < n; ++i) std::cin >> x, set.insert(x);
    int mx = *set.rbegin();
    for(auto i:set) k -= i;
    set.erase(--set.end());
    std::cout << mx << ' ';
    for(int i = 1; i < n; ++i) {
        if(k) {
            int mn = std::min(k, mx);
            std::cout << mn << ' ';
            if(!set.count(mn)) k -= mn;
            else set.erase(mn);
        } else std::cout << 0 << ' ';
    }
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}