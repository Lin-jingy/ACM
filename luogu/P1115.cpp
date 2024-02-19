#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    int ans = -1e4;
    int pre = -1e4;
    for(int i = 1; i <= n; ++i) {
        if(pre < 0) pre = 0;
        pre += a[i];
        ans = std::max(ans, pre);
    }
    std::cout << ans << '\n';
    return 0;
}