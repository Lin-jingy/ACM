#include<bits/stdc++.h>

#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::unordered_map<int, int> mp;
    for(int i = 0, x; i < n; ++i) std::cin >> x, mp[x]++;
    int ans = 0;
    for(auto [i, j]:mp) {
        int A = i + k;
        if(mp.count(A)) ans += j * mp[A];
    }
    std::cout << ans << '\n';

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