#include <iostream>
#include <queue>
#include <vector>

#define int long long

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    k = n - k;
    std::vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) std::cin >> a[i] >> b[i];
    std::priority_queue<std::pair<int, long long>,
                        std::vector<std::pair<int, long long>>, std::greater<std::pair<int, long long>>>
        q;
    std::vector<long long> ans(n + 1, 1e18);
    ans[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [w, p] = q.top();
        q.pop();
        if (ans[p] < w) continue;
        for (int i = 0; i < m; ++i) {
            int to = (a[i] + p) % n;
            int val = b[i] + w;
            if (ans[to] > val) {
                ans[to] = val;
                q.push({ans[to], to});
            }
        }
    }
    if (ans[k] == 1e18)
        std::cout << -1 << '\n';
    else
        std::cout << ans[k] << '\n';
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
