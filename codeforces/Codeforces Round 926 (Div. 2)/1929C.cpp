#include <bits/stdc++.h>

#define int long long

void solve() {
    int k, x, a;
    std::cin >> k >> x >> a;
    int ans = 0;
    for(int i = 1; i <= x + 1; ++i) {
        ans += ans / (k - 1) + 1;
        if(ans > a) break;
    }
    std::cout << (ans > a ? "NO\n" : "YES\n");

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}