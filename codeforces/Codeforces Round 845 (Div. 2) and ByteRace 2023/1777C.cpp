#if __GNUC__
#include <bits/stdc++.h>
#else
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define and &&
#define or ||
#endif
#if _WIN64 && __GNUC__
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
#if _WIN64 && __GNUC__
using int128 = __int128;
#endif

using PII = std::pair<int, int>;
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
    int n, m;
    std::cin >> n >> m;
    vec a(n);
    for (auto &i : a) std::cin >> i;
    std::sort(All(a));
    std::unordered_map<int, int> mp;
    auto fact = [&](int x, int k) -> void {
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                if (i <= m) mp[i] += k;
                if (x / i <= m) mp[x / i] += k;
                if (mp[i] == 0) mp.erase(i);
                if (mp[x / i] == 0) mp.erase(x / i);
            }
        }
    };
    int ans = INT_MAX;
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (mp.size() != m) q.push(a[i]), fact(a[i], 1);
        if (mp.size() == m) ans = std::min(ans, a[i] - a[i - q.size() + 1]);
        while (mp.size() == m) {
            fact(q.front(), -1), q.pop();
            if (mp.size() == m) ans = std::min(ans, a[i] - a[i - q.size() + 1]);
        }
    }
    if (ans == INT_MAX)
        std::cout << -1 << '\n';
    else
        std::cout << ans << '\n';
}