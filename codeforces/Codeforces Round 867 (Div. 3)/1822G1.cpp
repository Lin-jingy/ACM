#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    for(auto [i, j]:mp) {
        if(j >= 3) ans += j * (j - 1) * (j - 2);
        for(int k = 2; i * k * k <= 1e6; ++k) {
            if(mp.count(i * k) and mp.count(i * k * k)) {
                ans += j * mp[i * k] * mp[i * k * k];
            }
        }
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