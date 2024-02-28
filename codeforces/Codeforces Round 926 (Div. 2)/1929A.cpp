#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end(), std::greater<>());
    int ans = 0;
    for(int i = 1; i < n; ++i) ans += a[i - 1] - a[i];
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