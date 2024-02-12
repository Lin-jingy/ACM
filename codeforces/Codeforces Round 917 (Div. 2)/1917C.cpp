#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, k, d;
    std::cin >> n >> k >> d;
    std::vector<int> a(2 * n + 1), v(k + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= k; ++i) std::cin >> v[i];
    for (int i = n + 1; i <= 2 * n; ++i) a[i] = a[i - n];
    while (v.size() < 2 * n + 10) {
        for (int i = 1; i <= k; ++i) v.emplace_back(v[i]);
    }
    std::vector<int> mid(2 * n + 10);
    int ans = 0;
    for (int i = 1; i <= std::min(2 * n, d); ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j)
            if (j == a[j]) ++sum;
        mid[i] = sum;
        for (int j = 1; j <= v[i]; ++j) a[j]++;
    }
    for (int i = 1; i <= std::min(2 * n, d); ++i) {
        int day = d - i - 1;
        ans = std::max(ans, day / 2 + mid[i]);
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
