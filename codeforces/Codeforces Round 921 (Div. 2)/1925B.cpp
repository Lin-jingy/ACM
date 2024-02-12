#if __GNUC__
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
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
class Number {
public:
    static std::vector<int> get_prime(int n) {  // Euler
        std::vector<int> prime;
        std::vector<bool> not_prime(n + 1);

        for (int i = 2; i <= n; ++i) {
            if (!not_prime[i]) prime.push_back(i);
            for (int pri_j : prime) {
                if (i * pri_j > n) break;
                not_prime[i * pri_j] = true;
                if (i % pri_j == 0) break;
            }
        }
        return std::move(prime);
    }
    static bool isPrime(int n) {  // O(7logn)
        if (n < 3 || n % 2 == 0) return n == 2;
        int u = n - 1, t = 0;
        while (u % 2 == 0) u /= 2, ++t;
        auto quickPow = [](int a, int b, int p) {
            long long res = 1;
            while (b) {
                if (b & 1) res = (long long)res * a % p;
                a = (long long)a * a % p;
                b >>= 1;
            }
            return res;
        };
        int p[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
        for (int i = 0; i < 7; ++i) {
            int a = p[i] % (n - 2) + 2, v = quickPow(a, u, n);
            if (v == 1) continue;
            int s;
            for (s = 0; s < t; ++s) {
                if (v == n - 1) break;
                v = (long long)v * v % n;
            }
            if (s == t) return false;
        }
        return true;
    }
    static std::vector<int> get_factor(int x) {  // O(sqrt(x))
        std::vector<int> factor;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                factor.push_back(i);
                if (i != x / i) factor.push_back(x / i);
            }
        }
        return std::move(factor);
    }
    static std::vector<int> get_prime_factor(int x) {  // O(sqrt(x))
        std::vector<int> prime_factor;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                while (x % i == 0) x /= i;
                prime_factor.push_back(i);
            }
        }
        if (x != 1) prime_factor.push_back(x);
        return std::move(prime_factor);
    }
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int x, n;
    std::cin >> x >> n;
    std::vector<int> v = Number::get_factor(x);
    int ans = 0;
    for (auto i : v) {
        if (i * n <= x) ans = std::max(ans, i);
    }
    std::cout << ans << '\n';
}