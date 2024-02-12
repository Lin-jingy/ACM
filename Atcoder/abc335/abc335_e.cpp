#include <bits/stdc++.h>

#define LOCAL 0
#if LOCAL
#define dbg(x...)                  \
    do {                           \
        std::cout << #x << " -> "; \
        err(x);                    \
    } while (0)

void err() {
    std::cout << std::endl
              << std::endl;
}

template <class T, class... Ts>
void err(T arg, Ts... args) {
    std::cout << std::fixed << std::setprecision(10) << arg << ' ';
    err(args...);
}
#else
#define dbg(...)
#endif

using PII = std::pair<int, int>;
using i128 = __int128;
#define All(x) x.begin(), x.end()
#define eb(x) emplace_back(x)
using vec = std::vector<int>;
void solve();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    vec a(n + 1);
    std::vector<vec> v(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        v[x].eb(y);
        v[y].eb(x);
    }
    auto dijkstra = [&]() {
        std::vector<int> dis(n + 1, INT_MAX);
        std::vector<bool> st(n + 1);
        dis[1] = 0;
        std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
        q.push({0, 1});
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int ds = it.first, pos = it.second;
            if (st[pos]) continue;
            st[pos] = true;
            for (auto i : v[pos]) {
                if(a[i] )
                if (ds + 1 < dis[i]) {
                    dis[i] = ds + 1;
                    q.push({dis[i], i});
                }
            }
        }
    };
    std::cout << ans << '\n';
}