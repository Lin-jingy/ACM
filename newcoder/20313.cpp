#include <bits/stdc++.h>

#define int long long

std::vector<int> get_phi(int n) {
    std::vector<int> prime, phi(n + 1);
    std::vector<bool> vis(n + 1);
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; i * prime[j] <= n and j < prime.size(); ++j) {
            int k = i * prime[j];
            vis[k] = 1;
            if (i % prime[j] == 0)
                phi[k] = phi[i] * prime[j];
            else
                phi[k] = (prime[j] - 1) * phi[i];
        }
    }
    return std::move(phi);
}

signed main() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 0 << '\n';
        return 0;
    }
    std::vector phi = get_phi(n);
    int ans = 0;
    for (int i = 1; i < n; ++i) ans += phi[i];
    std::cout << ans * 2 + 1;
}