#include <bits/stdc++.h>

template<const int T>
struct ModInt {
    constexpr ModInt() = default;
    constexpr ModInt(int x) : x(x % T) {}
    constexpr ModInt(long long x) : x(x % T) {}
    constexpr int val() { return x; }
    constexpr ModInt operator+ (const ModInt a) const { int x0 = x + a.x; return ModInt(x0 < T ? x0 : x0 - T); }
    constexpr ModInt operator- (const ModInt a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + T : x0); }
    constexpr ModInt operator* (const ModInt a) const { return ModInt(1LL * x * a.x % T); }
    constexpr ModInt operator/ (const ModInt a) const { return *this * a.inv(); }
    constexpr bool operator== (const ModInt a) const { return x == a.x; };
    constexpr bool operator!= (const ModInt a) const { return x != a.x; };
    constexpr ModInt operator+= (const ModInt a) { x += a.x; if (x >= T) x -= T; return *this; }
    constexpr ModInt operator-= (const ModInt a) { x -= a.x; if (x < 0) x += T; return *this; }
    constexpr ModInt operator*= (const ModInt a) { x = 1LL * x * a.x % T; return *this; }
    constexpr ModInt operator/= (const ModInt a) { *this = *this / a; return *this; }
    constexpr friend ModInt operator+ (int y, const ModInt a){ int x0 = y + a.x; return ModInt(x0 < T ? x0 : x0 - T); }
    constexpr friend ModInt operator- (int y, const ModInt a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + T : x0); }
    constexpr friend ModInt operator* (int y, const ModInt a){ return ModInt(1LL * y * a.x % T);}
    constexpr friend ModInt operator/ (int y, const ModInt a){ return ModInt(y) / a;}
    constexpr friend std::ostream& operator<< (std::ostream &os, const ModInt a) { return os << a.x;}
    constexpr friend std::istream& operator>> (std::istream &is, ModInt t){return is >> t.x;}
    constexpr ModInt operator^ (long long n) const {
        ModInt res(1), mul(x);
        while(n){
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
private:
    int x = 0;
    constexpr ModInt inv() const {
        int a = x, b = T, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        if (u < 0) u += T;
        return u;
    }
};
using Mint = ModInt<998244353>;


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    Mint ans = 1;
    std::vector<Mint> p(n + 1, 0);
    for(int i = 1; i <= m; ++i) {
        int k;
        std::cin >> k;
        for(int j = 1; j <= k; ++j) {
            int x;
            std::cin >> x;
            p[x] += Mint(1) / Mint(k);
        }
    }
    for(int i = 1; i <= n; ++i) ans *= p[i];
    for(int i = n; i > 1; --i) ans *= i; 
    std::cout << ans << '\n';
    return 0;
}