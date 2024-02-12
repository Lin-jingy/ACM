#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int ans = 0;
    for (auto &i : a) std::cin >> i, ans += i * (n - 1);
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        int l = i, r = n - i - 1;
        ans += a[i] * (l - r);
    }
    std::cout << ans * 2 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}

// 2*min(i, j)