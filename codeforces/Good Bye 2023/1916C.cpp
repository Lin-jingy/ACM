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
    std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n;
    std::cin >> n;
    vec a(n);
    for (auto &i : a) std::cin >> i;
    int odds = 0, evens = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        (a[i] % 2 == 1 ? odds : evens)++;
        int odd = odds, even = evens;
        sum += a[i];
        int ans = sum;
        ans -= odd / 3;
        even += odd / 3;
        odd %= 3;
        int f = 0;
        while (odd and even) {
            if (f % 2 == 0) {
                if (odd >= 2) odd -= 2, even++;
                else odd--,  ans--;
            } else odd--, ans--;
            ++f;
        } 
        std::cout << ans << ' ';
    }
    std::cout << '\n';
}