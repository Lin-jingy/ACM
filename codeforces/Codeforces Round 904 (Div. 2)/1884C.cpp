#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i].first >> v[i].second;
    }
    int ans = 0;
    std::map<int, int> mp;
    for(auto [l, r] : v) {
        if(l != 1) mp[l]++, mp[r + 1]--;
    }
    int k = 0;
    for(auto i : mp) {
        k += i.second;
        ans = std::max(ans, k);
    }
    mp.clear();
    for(auto [l, r] : v) {
        if(r != m) mp[l]++, mp[r + 1]--;
    }
    k = 0;
    for(auto i : mp) {
        k += i.second;
        ans = std::max(ans, k);
    }
    std::cout << ans << '\n';

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}