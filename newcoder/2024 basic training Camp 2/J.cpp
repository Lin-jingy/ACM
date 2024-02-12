#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int ans = 0;
    for (auto &i : a) std::cin >> i;
    std::sort(a.begin(), a.end());
    ans += 2 * (n - 1) * a[0];
    for (int i = 1; i < n; ++i) {
        int num = n - i - 1;
        if (a[i] < 2 * a[0]) {
            ans += 2 * a[i] * num;
        } else {
            ans += 4 * a[0] * num;
        }
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