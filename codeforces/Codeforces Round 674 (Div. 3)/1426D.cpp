#include<bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1);
    int ans = 0;
    std::map<int, int> mp;
    mp[0] = 0;
    std::vector<std::pair<int, int>> v;
    for(int i = 1, x; i <= n; ++i) {
        std::cin >> x;
        p[i] = p[i - 1] + x;
        if(mp.count(p[i])) {
            v.push_back({mp[p[i]] + 1, i});
        }
        mp[p[i]] = i;
    }
    std::sort(v.begin(), v.end(), [&](std::pair<int, int>a, std::pair<int, int>b) {
        return a.second < b.second;
    });
    int last = 0;
    for(auto [l, r]:v) {
        if(l >= last) {
            ++ans;
            last = r;
        }
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