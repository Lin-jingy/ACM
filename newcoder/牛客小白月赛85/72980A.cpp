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
    std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int a = std::count(All(s), 'A');
    int c = std::count(All(s), 'C');
    int e = std::count(All(s), 'E');
    int p = std::count(All(s), 'P');
    int t = std::count(All(s), 'T');
    std::cout << std::min({a, c / 2, e, p, t}) << '\n';
}