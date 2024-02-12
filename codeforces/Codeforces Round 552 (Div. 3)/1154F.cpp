#include<bits/stdc++.h>

#define int long long 

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    while(a.size() > k) a.pop_back();
    std::map<int, int> mp;
    while(m--) {
        int x, y;
        std::cin >> x >> y;
        if(x > k) continue;
        int k = mp[x];
        mp[x] = std::max(k, y);
    }
    std::vector<int> dp(k + 1, LONG_LONG_MAX), pro(a.size() + 1);
    pro[1] = a[0];
    for(int i = 1; i < a.size(); ++i) {
        pro[i + 1] = pro[i] + a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= k; ++i) {
        for(auto [j, k]:mp) {
            if(i >= j) dp[i] = std::min(dp[i], dp[i - j] + pro[i] - pro[i - (j - k)]);
        }
        dp[i] = std::min(dp[i], dp[i - 1] + a[i - 1]);
    }
    std::cout << dp[k] << '\n';
    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}