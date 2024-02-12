#include<bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    int ans = INT_MAX;
    int gk = sqrt(n);
    for(int i = 1; i <= gk; ++i) {
        ans = std::min(ans, (n + i - 1) / i - 1 + i - 1);
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