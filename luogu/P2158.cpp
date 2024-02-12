#include <iostream>
#include <vector>

static std::vector<int> euler_phi_pre(int n) {  // 求1~n所有数的欧拉函数值
    std::vector<int> prime, phi(n + 1);
    std::vector<bool> not_prime(n + 1);
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int pri_j : prime) {   
            if (i * pri_j > n) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) {
                phi[i * pri_j] = phi[i] * pri_j;
                break;
            }
            phi[i * pri_j] = phi[i] * phi[pri_j];
        }
    }
    return std::move(phi);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 0 << '\n';
        return 0;
    }
    std::vector phi = euler_phi_pre(n);
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (long long)phi[i];
    }
    std::cout << ans * 2 + 1 << '\n';
    return 0;
}