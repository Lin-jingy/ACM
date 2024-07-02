#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n), c(m);
    for(int &i:a) std::cin >> i;
    for(int &i:b) std::cin >> i;
    for(int &i:c) std::cin >> i;
    int ans = 0;
    std::map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        if(mp.count(a[i]))mp[a[i]] = std::min(mp[a[i]], a[i] - b[i]);
        else mp[a[i]] = a[i] - b[i];
    }
    for(auto it = ++mp.begin(); it != mp.end(); ) {
        auto pre = it;
        --pre;
        if(it->second > pre->second) it = mp.erase(it);
        else ++it;
    }
    std::vector<int> dp(1e6 + 1);
    int mn = mp.rbegin()->second;
    auto it = ++mp.begin();
    for(int i = mp.begin()->first; i <= 1e6; ++i) {
        if(i == it->first) ++it;
        dp[i] = std::max(dp[i - 1], dp[i - (--it)->second] + 2);
        ++it;
    }
    for(auto &i:c) {
        if(i >= 1e6) {
            int num = (i - 1e6 - 10) / mn;
            ans += num * 2;
            i -= num * mn;
        }
        while(i > 1e6) i -= mn, ans += 2;
        ans += dp[i];
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}