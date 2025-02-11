#include <bits/stdc++.h>

#define int long long

struct node {
    int q, p;
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, r;
    std::cin >> n >> m >> r;
    std::vector<int> C(n), R(std::max(n, r));
    std::vector<node> P(m);

    for (int i = 0; i < n; ++i) std::cin >> C[i];
    for (int i = 0; i < m; ++i) std::cin >> P[i].q >> P[i].p;
    for (int i = 0; i < r; ++i) std::cin >> R[i];

    std::sort(C.begin(), C.end(), std::greater<>());
    std::sort(P.begin(), P.end(), [](node a, node b) { return a.p < b.p; });
    std::sort(R.begin(), R.end(), std::greater<>());
    while (R.size() > n) R.pop_back();
    std::reverse(R.begin(), R.end());

    int now = std::accumulate(R.begin(), R.end(), 0LL);
    int ans = now;
    for (int i = 0; i < n; ++i) {
        now -= R[i];
        int add = C[i];
        while (!P.empty() and add) {
            int dec = std::min(P.back().q, add);
            P.back().q -= dec;
            add -= dec;
            now += dec * P.back().p;
            if (P.back().q == 0) P.pop_back();
        }
        ans = std::max(ans, now);
    }

    std::cout << ans << '\n';

    return 0;
}