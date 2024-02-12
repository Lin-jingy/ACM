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
#define int long long
using PII = std::pair<int, int>;
using i128 = __int128;
#define All(x) x.begin(), x.end()
#define eb(x) emplace_back(x)
#define push_back(x) eb(std::move(x))
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
int operator -(PII a, PII b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int dis[105][105];

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n + 1);
    for(int i = 2; i < n; ++i) std::cin >> a[i];
    std::vector<PII> v(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> v[i].first >> v[i].second;
    for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j) {
        dis[i][j] = (v[i] - v[j]) * d - a[j];
        dis[j][i] = (v[i] - v[j]) * d - a[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int k = 1; k <= n; ++k) {
                if(dis[j][k] > dis[j][i] + dis[i][k]) dis[j][k] = dis[j][i] + dis[i][k];
            }
        }
    }
    std::cout << dis[1][n] << '\n';
}