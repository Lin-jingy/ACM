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
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    long long n;
    std::cin >> n;
    n += 1;
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    int sz = (int)digits.size();
    long long ans = 0;
    for (int sum = 1; sum <= sz * 9; sum++) {
        std::vector<std::vector<std::vector<std::vector<long long>>>>
            dp(sz + 1, std::vector<std::vector<std::vector<long long>>>(
                           2, std::vector<std::vector<long long>>(sum + 1, std::vector<long long>(sum + 1))));
        dp[sz][0][0][0] = 1;
        for (int i = sz; i > 0; i--) {
            for (int ls = 0; ls < 2; ls++) {
                for (int s = 0; s <= sum; s++) {
                    for (int r = 0; r < sum; r++) {
                        auto ft = dp[i][ls][s][r];
                        if (ft == 0) {
                            continue;
                        }
                        int lim = (ls ? 9 : digits[i - 1]);
                        for (int d = 0; d <= lim && s + d <= sum; d++) {
                            dp[i - 1][ls | (d < lim)][s + d][(r * 10 + d) % sum] += ft;
                        }
                    }
                }
            }
        }
        ans += dp[0][1][sum][0];
    }
    std::cout << ans << '\n';
}
