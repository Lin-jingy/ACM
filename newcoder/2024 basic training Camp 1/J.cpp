#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    auto check = [&](int k) -> bool {
        std::set<int> s;
        s.insert(x);
        int p = y;
        for (auto x : a) {
            if (!s.empty() && abs(p - x) <= k) {
                s.insert(p);
            }
            while (!s.empty() && *s.begin() < x - k) {
                s.erase(s.begin());
            }
            while (!s.empty() && *s.rbegin() > x + k) {
                s.erase(*s.rbegin());
            }
            if (s.empty()) return false;
            p = x;
        }
        return true;
    };

    int l = abs(x - y), r = 2e9, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1, ans = mid;
        } else {
            l = mid + 1;
        }
    }

    std::cout << ans << '\n';

    return 0;
}
