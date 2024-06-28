#include <bits/stdc++.h>

namespace Math {
constexpr static std::vector<int> get_prime(const int n) {  // Euler
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
constexpr static long long quickPow(int a, int b, const int p) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return res;
}

constexpr static bool isPrime(const int n) {  // O(7logn)
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
constexpr static std::vector<int> get_factor(const int x) {  // O(sqrt(x))
    std::vector<int> factor;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            factor.push_back(i);
            if (i != x / i) factor.push_back(x / i);
        }
    }
    return factor;
}
constexpr static std::vector<int> get_prime_factor(int x) {  // O(sqrt(x))
    std::vector<int> prime_factor;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            prime_factor.push_back(i);
        }
    }
    if (x != 1) prime_factor.push_back(x);
    return prime_factor;
}
constexpr static int euler_phi(int n) {  // 求一个数的欧拉函数值
                               // 小于等于 n 和 n 互质的数的个数
    int m = sqrt(n + 0.5);
    int ans = n;
    for (int i = 2; i <= m; i++)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}
constexpr static std::vector<int> euler_phi_pre(const int n) {  // 求1~n所有数的欧拉函数值
    std::vector<int> prime, phi(n + 1);
    std::vector<bool> not_prime(n + 1);
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j : prime) {
            if (i * j > n) break;
            not_prime[i * j] = true;
            if (i % j == 0) {
                phi[i * j] = phi[i] * j;
                break;
            }
            phi[i * j] = phi[i] * phi[j];
        }
    }
    return phi;
}
constexpr static int Exgcd(const int a, const int b, int &x, int &y) {
    // ax * by ===
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = Exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
constexpr static std::vector<int> get_inv(const int n, const int p) {
    std::vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    return inv;
}
constexpr static long long CRT(const std::vector<int> &a, const std::vector<int> &p) {  // 中国剩余定律
/*
   a1 % p1 = x
   a2 % p2 = x
   ...
*/
    long long n = 1, ans = 0;
    int k = a.size();
    for (int i = 0; i < k; i++) n = n * p[i];
    for (int i = 0; i < k; i++) {
        long long m = n / p[i];
        int b, y;
        Exgcd(m, p[i], b, y);  // b * m mod r[i] = 1
        ans = (ans + a[i] * m * b % n) % n;
    }
    return (ans % n + n) % n;
}
};  // namespace Math