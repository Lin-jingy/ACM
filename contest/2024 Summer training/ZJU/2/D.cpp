#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> c(n + 1);
    std::set<int> count;
    for(int i = 1; i <= n; ++i) std::cin >> c[i], count.insert(c[i]);
    
    int ans = count.size();

    



    return 0;
}
