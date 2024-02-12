#include <bits/stdc++.h>

int lcm(int a, int b) {
    return a * b / std::__gcd(a, b);
}

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    long long ans = 0;
    auto fact = [&](int l, int r) -> long long {
        return 1ll * (r - l + 1) * (l + r) / 2;
    };
    ans += fact(n - n / a + 1, n);
    long long num = 1ll * n / std::lcm(a, b);
    ans -= fact(n - n / a + 1, n - n / a + num);
    ans -= fact(1, n / b - num);
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
