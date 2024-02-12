#include <bits/stdc++.h>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n), b(m);
    for (auto &i : a) std::cin >> i;
    for (auto &i : b) std::cin >> i;
    std::set<int> s;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    int l = 0;
    int r = 0;
    for (auto i : a) {
        if (i <= k) s.insert(i), l++;
    }

    for (auto i : b) {
        if (i <= k) s.insert(i), r++;
    }
    if (s.size() == k and l >= k / 2 and r >= k / 2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
