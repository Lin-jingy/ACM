#include<bits/stdc++.h>

#define int long long

void solve() {
    int l, r;
    std::cin >> l >> r;
    int ans = (r - l + 1) % 9 * (l + r) * 5 % 9;
    std::cout << ans << '\n';
    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}