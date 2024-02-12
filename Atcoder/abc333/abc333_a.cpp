#include <bits/stdc++.h>
#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = ans * 10 + n;
    std::cout << ans << '\n';
    return 0;
}
