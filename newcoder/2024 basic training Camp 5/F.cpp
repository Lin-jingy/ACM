#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    if(n == 1) {
        std::cout << "0\n";
        return ;
    }
    if(n % 2 == 1) {
        int k = 0;
        int ans = 0;
        for(int i = n - 1; i >= 1; i--) {
            int r1 = a[i + 1] + k * (i + 1);
            int r0 = a[i] + k * i;
            if(r1 < r0) {
                std::cout << "-1\n";
                return ;
            }
            if(i % 2 == 0) k += (r1 - r0) / i;
        }
    }
    int ans = 0;
    for(int i = n - 1; i >= 1; --i) 
        ans = std::max(ans, a[i] - a[i + 1]);
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}