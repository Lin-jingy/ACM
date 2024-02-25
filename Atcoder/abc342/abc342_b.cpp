#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> P(n + 1), pos(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> P[i], pos[P[i]] = i;
    int q;
    std::cin >> q;
    while(q--) {
        int a, b;
        std::cin >> a >> b;
        // int mn = pos[a];
        // for(int i = a; i <= b; ++i) mn = std::min(mn, pos[i]);
        // std::cout << P[mn] << '\n';
        if(pos[a] < pos[b]) std::cout << a << '\n';
        else std::cout << b << '\n';

    }

    return 0;
}