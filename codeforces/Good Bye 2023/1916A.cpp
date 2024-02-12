#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int sum = 1;
    for (auto &i : a) std::cin >> i, sum *= i;
    if (2023 % sum == 0) {
        std::cout << "YES\n";
        int x = 2023 / sum;
        std::cout << x << ' ';
        k--;
        while (k--) std::cout << 1 << ' ';
        std::cout << '\n';
    } else {
        std::cout << "NO\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
