#include <bits/stdc++.h>

#define int long long


constexpr static long long quickPow(int a, int b, const int p) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return res;
}

constexpr static bool isPrime(const int n) {
    if (n < 3 || n % 2 == 0) return n == 2;
    int u = n - 1, t = 0;
    while (u % 2 == 0) u /= 2, ++t;
    constexpr int p[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (int i = 0; i < 7; ++i) {
        int a = p[i] % (n - 2) + 2, v = quickPow(a, u, n);
        if (v == 1) continue;
        int s = 0;
        for (; s < t; ++s) {
            if (v == n - 1) break;
            v = (long long)v * v % n;
        }
        if (s == t) return false;
    }
    return true;
}

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

auto prime = get_prime(1000005);

void solve() {
    int n, k;
    std::cin >> n >> k;
    if(k == 1) {
        std::cout << "Alice\n";
        return ;
    }
    if(isPrime(n)) {
        std::cout << "Bob\n";
        return ;
    }
    
    
    for(auto i:prime) {
        if(n % i == 0) {
            if(i > n) break;
            int num = 0;
            while(n % i == 0) n /= i, ++num;
            if(num >= k) {
                std::cout << "Alice\n";
                return ;
            }
        }
    }
    std::cout << "Bob\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}