#include<bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    long long suma = 0, sumb = 0;
    int mna = INT_MAX, mnb = INT_MAX;
    for(int i = 0; i < n; ++i) std::cin >> a[i], suma += a[i], mna = std::min(mna, a[i]);
    for(int i = 0; i < n; ++i) std::cin >> b[i], sumb += b[i], mnb = std::min(mnb, b[i]);
    long long ans = LONG_LONG_MAX;
    std::cout << std::min(1ll * mna * n + sumb, 1ll * mnb * n + suma) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}