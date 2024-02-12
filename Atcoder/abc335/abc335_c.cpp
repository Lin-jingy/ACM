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
    int n, q;
    std::cin >> n >> q;
    std::vector<PII> a;
    for (int i = n; i >= 1; --i) a.eb(PII(i, 0));
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            char x;
            std::cin >> x;
            if (x == 'U')
                a.eb(PII(a.back().first, a.back().second + 1));
            else if (x == 'D')
                a.eb(PII(a.back().first, a.back().second - 1));
            else if (x == 'R')
                a.eb(PII(a.back().first + 1, a.back().second));
            else if (x == 'L')
                a.eb(PII(a.back().first - 1, a.back().second));
        } else {
            int p;
            std::cin >> p;
            std::cout << a[a.size() - p].first << ' ' << a[a.size() - p].second << '\n';
        }
    }
}