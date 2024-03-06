#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> du(n);
    while(m--) {
        int x, y;
        std::cin >> x >> y;
        du[x - 1]++;
        du[y - 1]++;
    }
    std::sort(du.begin(), du.end());
    int s0 = std::count(du.begin(), du.end(), 1);
    std::cout << n - 1 - s0 << ' '  << s0 / (n - 1 - s0) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}