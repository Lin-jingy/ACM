#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5 + 5;
constexpr int mod = 1e9 + 7;
int inv[N], pre[N];

constexpr int qpow(int a, int b) {
    int sum = 1;
    while(b) {
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}
constexpr void init() {
    inv[0] = pre[0] = 1;
    for(int i = 1; i < N; ++i) {
        pre[i] = pre[i - 1] * i % mod;
        inv[i] = qpow(pre[i], mod - 2);
    }
}

constexpr int C(int a, int b) {
    if(a < b) return 0;
    b = std::min(b, a - b);
    return pre[a] * inv[b] % mod * inv[a - b] % mod;
}