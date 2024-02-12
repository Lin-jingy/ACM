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

char ch(int x) {
    if (x >= 0 and x <= 9) return x + '0';
    return 'A' + x - 10;
}

void solve() {
    int n, p;
    std::cin >> n >> p;
    int cn = n;
    std::string s;
    while (n) {
        int k = n % p;
        if (k < 0) k -= p, n += p;
        s += ch(k);
        n /= p;
    }
    std::reverse(All(s));
    std::cout << cn << "=" << s << "(base" << p << ")" << '\n';
}