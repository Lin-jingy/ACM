#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int &i:a) std::cin >> i;
    std::sort(a.begin(), a.end());
    std::cout << std::max(a[0] * a[1], a[n - 1] * a[n - 2]) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}