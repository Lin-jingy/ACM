#include <bits/stdc++.h>


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("1.out", "r", stdin);
    int n;
    std::cin >> n;
    int N = 199;
    std::set<std::pair<int, int>> s;
    for(int i = 1; i <= N; ++i) {
        for(int j = i + 1; j <= N; ++j) {
            s.insert({i, j});
        }
    }
    for(int i = 1; i <= n; ++i) {
        std::vector<int> a(N);
        for(int j = 0; j < N; ++j) std::cin >> a[j];
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                if(s.count({a[j], a[k]})) s.erase({a[j], a[k]});
                if(s.count({a[k], a[j]})) s.erase({a[k], a[j]});
            }
        }
        // std::cout << i << std::endl;
    }
    std::cout << s.size() << std::endl;
    for(auto [i,j]:s) {
        std::cout << i << ' ' << j << '\n';
    }
    return 0;
}