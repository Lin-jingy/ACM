#include <bits/stdc++.h>

#define int long long
const int mod = 998244353;

int qpow(int a, int b) {
    int sum = 1;
    while (b) {
        if (b & 1)
            sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> ans(n + 1);
    for (int i = 2; i <= n; ++i) {
        int l = i, r = i + 1;
        if(r == n + 1)
            r = 1;
        ans[l] = (ans[l] + qpow(3, mod - 2) * qpow(qpow(2, i - 1), mod - 2) % mod) % mod;
        ans[r] = (ans[r] + 2 * qpow(3, mod - 2) % mod * qpow(qpow(2, i - 1), mod - 2) % mod) % mod;
    }
    int qn = qpow(2, n);
    int q = (qn - 1) * qpow(qn, mod - 2);
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] * qpow(q, mod - 2) % mod << ' ';
    }

        return 0;
}
