#include <bits/stdc++.h>

#define int long long

// std::map<std::multiset<int>, int> mp;
// int sg(std::multiset<int> s) {
//     if(s.empty()) return 0;
//     if(mp.count(s)) return mp[s];
//     auto it = s;
//     for(auto i:s) {
//         s.erase(s.find(i));
//         for(int j = 1; j < i; ++j) s.insert(j);
//         if(sg(s) == 0) return mp[it] = 1;
//         for(int j = 1; j < i; ++j) s.erase(s.find(j));
//         s.insert(i);
//     }
//     return mp[it] = 0;
// }

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if(a[i] >= 2) a[i] = 2;
        ans ^= a[i];
    }
    if(ans) std::cout << "Yes\n";
    else std::cout << "No\n";
    // std::multiset<int> s;
    // for(int i = 0; i < n; ++i) std::cin >> a[i], s.insert(a[i]);
    // sg(s);
    // for(auto &i:mp) {
    //     for(auto j:mp.first)
    // }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}