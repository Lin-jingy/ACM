#include <bits/stdc++.h>

static constexpr std::vector<int> get_inv(int n, int p) {
    std::vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    return inv;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector a = get_inv(n, q);
    for (int i = 1; i <= n; ++i) std::cout << a[i] << '\n';
    return 0;
}