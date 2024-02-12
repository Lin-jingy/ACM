#include <bits/stdc++.h>

#define int long long
constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
    int sum = 1;
    while (b) {
        if (b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

static std::vector<int> get_inv(int n) {
    std::vector<int> inv(n + 1), f(n + 1);
    f[1] = inv[1] = inv[0] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] * i % mod;
        inv[i] = qpow(f[i], mod - 2);
    }
    // inv[1] = 1;
    // for (int i = 2; i <= n; ++i) inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    return std::move(inv);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    if (n < m) {
        std::cout << 0 << '\n';
        return 0;
    }
    int ans = 0;
    std::vector<int> inv = get_inv(1e6);
    for (int i = 0; i <= m; ++i) {
        ans += qpow(-1, m - i) * qpow(i, n) % mod * inv[i] % mod * inv[m - i] % mod;
        ans %= mod;
    }
    std::cout << (ans + mod) % mod << '\n';
    return 0;
}
