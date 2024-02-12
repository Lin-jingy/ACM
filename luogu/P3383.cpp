#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

static std::vector<int> get_prime(int n) {  // Euler
    std::vector<int> prime;
    std::vector<bool> not_prime(n + 1);

    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) prime.push_back(i);
        for (int pri_j : prime) {
            if (i * pri_j > n) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) break;
        }
    }
    return std::move(prime);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, q;
    std::cin >> n >> q;
    std::vector prime = get_prime(n);
    while (q--) {
        int x;
        std::cin >> x;
        std::cout << prime[x - 1] << '\n';
    }
    return 0;
}