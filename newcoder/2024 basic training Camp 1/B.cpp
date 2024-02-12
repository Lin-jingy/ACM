#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int ans = 3;
    int l = 0, r = 0;
    std::set<std::pair<int, int>> s;
    while (n--) {
        int r, c;
        std::cin >> r >> c;
        s.insert({c, r});
    }
    for (auto [y, x] : s) {
        if (y <= 0) l = std::max(l, 1);
        if (y >= 0) r = std::max(r, 1);
        if (s.count({y, 3 - x}) or s.count({y + 1, 3 - x})) {
            if (y < 0) l = 2;
            if (y >= 0) r = 2;
        }
    }
    ans = std::min(4 - l - r, ans);
    if (s.count({-1, 1}) and s.count({1, 1}) and s.count({0, 2})) {
        ans = 0;
    } else if ((s.count({-1, 1}) and s.count({1, 1})) or (s.count({-1, 1}) and s.count({0, 2})) or (s.count({1, 1}) and s.count({0, 2}))) {
        ans = std::min(ans, 1);
    } else if (s.count({-1, 1}) or s.count({1, 1}) or s.count({0, 2})) {
        ans = std::min(ans, 2);
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
