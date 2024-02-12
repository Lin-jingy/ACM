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
#define int long long
using PII = std::pair<int, int>;
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
    int x;
    std::cin >> x;
    vec a;
    while (x) {
        a.eb(x % 5);
        x /= 5;
    }
    std::reverse(All(a));
    if (a.back() != 0) {
        a.back()--;
    } else {
        a.back() = 4;
        for (int i = a.size() - 2; i >= 0; --i) {
            if (a[i] == 0) {
                a[i] = 4;
            } else {
                a[i]--;
                break;
            }
        }
    }
    for (auto i : a | std::views::transform([](int x) { return x * 2; })) std::cout << i;
}