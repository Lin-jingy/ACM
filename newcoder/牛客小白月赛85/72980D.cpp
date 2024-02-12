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

void solve() {
    int n, m;
    std::cin >> n >> m;
    vec a(n + 1), v;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    int ans = 0, add = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            v.eb(add);
            add = 0;
        }
        add += a[i];
    }
    add = 0;
    while (!v.empty()) {
        if (add + v.back() >= m) break;
        add += v.back();
        v.pop_back();
    }
    add = 0;
    for (auto i : v) {
        if (i >= m) {
            std::cout << "NO\n";
            return;
        }
        if (add + i >= m) {
            ans += add;
            add = 0;
        }
        add += i;
    }
    ans += add;
    std::cout << ans + n - 1 << '\n';
}
