#include <bits/stdc++.h>

static std::vector<int> get_prime(const int n) {  // Euler
    std::vector<int> prime;
    std::vector<bool> not_prime(n + 1);

    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) prime.push_back(i);
        for (int j : prime) {
            if (i * j > n) break;
            not_prime[i * j] = true; 
            if (i % j == 0) break;
        }
    }
    return prime;
}

auto prime = get_prime(20000010);

void solve() {
    int l, r;
    std::cin >> l >> r;
    ++l, ++r;
    auto L = std::lower_bound(prime.begin(), prime.end(), l);
    auto R = std::upper_bound(prime.begin(), prime.end(), r);
    int ans = R - L;
    if(l == 2) --ans;
    if(l <= 4 and r >= 4) ++ans;
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}