#include <bits/stdc++.h>

void solve() {
    int n, x;
    std::cin >> n;
    std::vector<int> l1, l2;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (x == 1)
            l1.push_back(i);
        else
            l2.push_back(i);
    }
    int ans = 0;
    int p = n - 1;
    while (!l1.empty() and !l2.empty()) {
        p = std::min(l1.back(), l2.back());
        ans++;
        while (!l1.empty() and l1.back() >= p) l1.pop_back();
        while (!l2.empty() and l2.back() >= p) l2.pop_back();
    }
    ans += l1.size() + l2.size();
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
