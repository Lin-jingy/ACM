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
    std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n;
    std::cin >> n;
    std::unordered_map<int, int> mp;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) mp[i]++, n /= i;
    }
    if (n != 1) mp[n]++;
    int ans = 0;
    while (!mp.empty()) {
        int k = 1;
        for (auto &[i, j] : mp) {
            k *= i;
            j--;
        }
        ans += k;
        for (auto it = mp.begin(); it != mp.end();) {
            if (it->second == 0)
                it = mp.erase(it);
            else
                ++it;
        }
    }
    std::cout << ans << '\n';
}