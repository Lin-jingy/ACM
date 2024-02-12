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
#include <ranges>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define or ||
#define and &&
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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (n % 2 != 0 or std::count(All(s), '(') != n / 2) {
        std::cout << "-1\n";
        return;
    }
    if (s.front() == ')') {
        for (auto &i : s) i = (i == '(' ? ')' : '(');
    }
    vec ans(n, 2), prov(n);
    prov.back() = (s.back() == ')');
    for (int i = n - 2; i >= 0; --i) prov[i] = prov[i + 1] + (s[i] == ')');
    // dbg(prov[0]);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' and prov[i] >= k + 1)
            ++k, ans[i] = 1;
        else if (s[i] == ')' and k > 0)
            --k, ans[i] = 1;
    }
    auto fact = [](int i) { return i == 2 ? 1 : i; };
    if (std::count(All(ans), 2) == n) {
        int k = 1 + (std::count(All(ans), 1) != 0);
        std::cout << k << '\n';
        for (auto i : ans | std::ranges::views::transform(fact)) std::cout << i << ' ';
    } else {
        int k = 1 + (std::count(All(ans), 2) != 0);
        std::cout << k << '\n';
        for (auto i : ans) std::cout << i << ' ';
    }
    std::cout << '\n';
}