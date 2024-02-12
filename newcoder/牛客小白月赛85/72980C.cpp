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

const double eps = 1e-9;

void solve() {
    int n;
    std::cin >> n;
    vec a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    double ansl = a[1], ansr = a[1] + 1;
    for (int i = 1; i <= n; ++i) {
        ansl = std::max(ansl, 1.0 * a[i] / i);
        ansr = std::min(ansr, 1.0 * (a[i] + 1) / i);
    }
    printf("%.10lf", ansr);
}
