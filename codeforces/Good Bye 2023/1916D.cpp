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
void init();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    init();
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}

std::array<std::vector<std::string>, 100> a;

void init() {
    a[1].eb("1");
    a[3].eb("169"), a[3].eb("196"), a[3].eb("961");
    for (int i = 5; i <= 99; i += 2) {
        for (auto j : a[i - 2]) a[i].eb(j + "00");
        std::string s;
        for (int j = 1; j <= i; ++j) s += '0';
        s[0] = '1', s[i / 2] = '6', s[i - 1] = '9';
        a[i].eb(s);
        s[0] = '9', s[i - 1] = '1';
        a[i].eb(s);
    }
}

void solve() {
    int n;
    std::cin >> n;
    for (auto i : a[n]) std::cout << i << '\n';
}