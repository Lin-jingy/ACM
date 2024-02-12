#include<bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::array<std::array<int, 2>, 10> dp;
    while(n--) {
        int m;
        std::cin >> m;
        std::vector<int> a(m);
        for(int i = 0; i < m; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end(), std::greater<>());
        for(int i = 0; i < std::min(4, a.size()); ++i) {
            
        }
    }


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