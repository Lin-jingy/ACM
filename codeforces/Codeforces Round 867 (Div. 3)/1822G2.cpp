#include <bits/stdc++.h>
#include <google/dense_hash_map>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> mp;
    llvm::dense_map<int, int> mp1;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
        mp[a[i]]++;
    }
    long long ans = 0;
    if(n <= 2e3) {
        for(auto [i, j]: mp) {
            if(j >= 3) ans += 1LL * j * (j - 1) * (j - 2);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j or a[i] == a[j]) continue;
                if(a[j] % a[i] == 0 and 1LL * a[j] * (a[j] / a[i]) <= mx and mp.count(a[j] * (a[j] / a[i]))) {
                    ans += 1LL * mp[a[j] * (a[j] / a[i])];
                }
            }
        }
    } else {
        for(auto [i, j]:mp) {
            if(j >= 3) ans += 1LL * j * (j - 1) * (j - 2);
            for(int k = 2; 1LL * i * k * k <= mx; ++k) {
                if(mp.count(i * k) and mp.count(i * k * k)) {
                    ans += 1LL * j * mp[i * k] * mp[i * k * k];
                }
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