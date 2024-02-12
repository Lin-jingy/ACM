#include <bits/stdc++.h>

#define int long long
constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
    int s = 1;
    while (b) {
        if (b & 1) s = s * b % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return s;
}

static std::vector<int> get_inv(int n, int p) {
    std::vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    return std::move(inv);
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(m), inv = get_inv(n, mod);
    int ans = 0, sum = 0;
    for (int i = 0, x; i < m; ++i) {
        std::cin >> x >> x >> a[i];
        sum += a[i];
    }
    sum %= mod;
    int p = 2 * inv[n] % mod * inv[n - 1] % mod;
    for (int i = 1; i <= k; ++i) {
        ans = (ans + p * sum % mod) % mod;
        sum = (sum + p * m % mod) % mod;
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
