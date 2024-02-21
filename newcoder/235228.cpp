#include <bits/stdc++.h>

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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int l, r;
    std::cin >> l >> r;
    int ans = 0;
    for(int i = l; i <= r; ++i) if(isPrime(i)) ++ans;
    std::cout << ans << '\n';

    return 0;
}