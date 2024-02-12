#include <algorithm>
#include <iostream>
#include <string>

long long qpow(long long a, long long b, long long mod) {
    long long sum = 1;
    while (b) {
        if (b & 1) sum = sum * a % mod;
        a = a * a % mod;
        b >>= 1LL;
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    long long a, m;
    std::string b;
    std::cin >> a >> m >> b;
    long long ans = 1;
    while (b.size() >= 16) {
        std::string mid;
        for (int i = 0; i < 16; ++i) mid += b.back(), b.pop_back();
        std::reverse(mid.begin(), mid.end());
        ans = qpow(ans, 1e16, m) * qpow(a, stoll(mid), m) % m;
    }
    if (!b.empty()) ans = qpow(ans, 1e16, m) * qpow(a, stoll(b), m) % m;
    std::cout << ans << '\n';
}