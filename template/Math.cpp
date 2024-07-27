#include <bits/stdc++.h>

/**
 * @brief 一些数学的函数
 */
namespace Math {

/** 
 * @brief 欧氏筛求素数
 * @param n 范围
 * @note O(n)
 * @return 包含1~n所有质数的vec
 */
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

/** 
 * @brief 快速幂
 * @param a 底数
 * @param b 指数
 * @param p 模数
 * @note O(logb)
 * @return a^b%p的结果
 */
constexpr static long long quickPow(int a, int b, const int p) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return res;
}

/** 
 * @brief 素性检测
 * @param n 被检测数
 * @note O(7logn)
 * @return 返回是否是素数的一个bool值
 */
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

/** 
 * @brief 求一个数的因子
 * @param 这个数
 * @note O(sqrt(x)) 
 * @return 包含这个数所有因子的vec
 */
constexpr static std::vector<int> get_factor(const int x) {
    std::vector<int> factor;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            factor.push_back(i);
            if (i != x / i) factor.push_back(x / i);
        }
    }
    return factor;

}

/** 
 * @brief 求一个数的质因子
 * @param 这个数
 * @note O(sqrt(x)) 当x=1时，返回空vector
 * @return 包含这个数所有质因子的vec
 */
constexpr static std::vector<int> get_prime_factor(int x) {
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

/** 
 * @brief 求一个数的欧拉函数值
 * @param 这个数
 * @note O(sqrt(n))
 * @return 欧拉函数数值
 */
constexpr static int euler_phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) res = res / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) res = res / n * (n - 1);
    return res;
}

/** 
 * @brief 求1~n所有数的欧拉函数值
 * @param 范围
 * @note O(nlognlogn)
 * @return 1~n所有数的欧拉函数的数值
 */
[[deprecated]] constexpr static std::vector<int> phi_pre(const int n) {
    std::vector<int> phi(n + 1);
    // 除1外没有数的欧拉函数是本身，所以如果phi[i] = i则说明未被筛到
    for (int i = 1; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++)
        if (phi[i] != i) // 未被筛到
            for (int j = i; j <= n; j += i) // 所有含有该因子的数都进行一次操作
                phi[j] = phi[j] / i * (i - 1);
    return phi;
}

/** 
 * @brief 求1~n所有数的欧拉函数值
 * @param 范围
 * @note O(n)
 * @return 1~n所有数的欧拉函数的数值
 */
constexpr static std::vector<int> euler_phi_pre(const int n) {
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
constexpr static std::vector<int> get_inv(const int n, const int p) {
    std::vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    return inv;
}
constexpr static int C(int a, int b, int p) {
    //TODO
    return 0;
}
/** 
 * @brief 求C(n, m) % p
 * @param 
 * @note O(logn) 卢卡斯定理
 * @return C(n, m) % p的结果
 */
constexpr static long long Lucas(long long n, long long m, long long p) {
    if (m == 0) return 1;
    return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}
/** 
 * @brief 求(n!)%p
 * @param 
 * @note O(p + log_p(n))
 * @return (n!) % p的结果
 */
constexpr static int factmod(int n, int p) {
    std::vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++) f[i] = f[i - 1] * i % p;
    int res = 1;
    while (n > 1) {
        if ((n / p) % 2) res = p - res;
        res = res * f[n % p] % p;
        n /= p;
    }
    return res;
}

/** 
 * @brief 求ax+by=m
 * @param 
 * @note O(log(a+b)) 裴蜀定理
 * @return gcd(a,b)的结果
 */
constexpr static int Exgcd(const int a, const int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = Exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
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
