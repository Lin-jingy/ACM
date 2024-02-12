#include<bits/stdc++.h>
#define int long long 

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int ans = LONG_LONG_MAX;
    for(int i = 0; i < 32; ++i) {
        int k = 1ll << i;
        int mn = 0;
        mn += a * i;
        mn += (c + k - 1) / k * b;
        ans = std::min(ans, mn);
    }
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