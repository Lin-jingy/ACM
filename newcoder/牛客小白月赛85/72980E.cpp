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

struct node {
    int i, l, r;
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<PII> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) std::cin >> a[i].first, sum += a[i].first, a[i].second = i + 1;
    std::sort(All(a));
    int t = (sum + m - 1) / m;
    std::vector<std::vector<node>> ans(m + 1);
    for (int i = 1; i <= m; ++i) {
        int k = 0;
        while (!a.empty() and a.back().first <= t - k) {
            ans[i].push_back({a.back().second, k, k + a.back().first});
            k += a.back().first;
            a.pop_back();
        }
    }
}