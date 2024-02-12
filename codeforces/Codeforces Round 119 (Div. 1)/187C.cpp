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
#define push_back(x) emplace_back(std::move(x))
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
    //std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<bool> f(n + 1);
    for (int i = 1, x; i <= k; ++i) {
        std::cin >> x;
        f[x] = 1;
    }
    std::vector<vec> v(n + 1);
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        v[x].eb(y);
        v[y].eb(x);
    }
    int begin, end;
    std::cin >> begin >> end;
    auto check = [&](int x) -> bool {
        std::vector<int> d(n + 1);
        std::queue<PII> q;
        q.push({begin, x});
        d[begin] = x;
        while (!q.empty()) {
            auto [pos, dis] = q.front();
            q.pop();
            dis--;
            if(f[pos]) dis = x;
            if(pos == end) return true;
            if(dis == 0) continue;
            for (auto i:v[pos]) {
                if(d[i] < dis) d[i] = dis, q.push({i, dis});
            }
        }
        return false;
    };
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    std::cout << ans << '\n';
}