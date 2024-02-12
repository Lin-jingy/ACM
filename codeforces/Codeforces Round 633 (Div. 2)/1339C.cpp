#include <iostream>
#include <vector>

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
// using i128 = __int128;
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
    auto check = [&](int x) -> bool {
        std::vector<int> ma = a;
        for (int i = 1; i < n; ++i) {
            if (ma[i] < ma[i - 1]) {
                if (ma[i - 1] - ma[i] > (1LL << x) - 1) return false;
                ma[i] = ma[i - 1];
            }
        }
        return true;
    };
    int l = 0, r = 31, ans = 0;
    vec v(100);
    
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    std::cout << ans << '\n';
}