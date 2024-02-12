#include <iostream>
#include <queue>
#include <vector>

void solve() {
    int a, b;
    std::cin >> a >> b;
    int n = a + b, f = 1;
    std::vector<std::pair<int, int>> ans(n + 1, {-1, -1});
    std::queue<std::pair<int, int>> q;
    q.push({1, 1});
    a--;
    while ((a || b) && !q.empty()) {
        auto [pos, color] = q.front();
        q.pop();
        if (color && b >= 2)b -= 2;
        else if (!color && a >= 2)a -= 2;
        else continue;
        int l = ++f, r = ++f;
        q.push({l, color ^ 1});
        q.push({r, color ^ 1});
        ans[pos] = {l, r};
    }
    if (a == 0 and b == 0) {
        std::cout << "YES\n";
        for (int i = 1; i <= n; ++i) std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    } else std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
