#include <bits/stdc++.h>

// #define constexpr inline

template <const int T>
struct ModInt {
    constexpr ModInt() = default;
    constexpr ModInt(int x) : x(x % mod) {}
    constexpr ModInt(long long x) : x(x % mod) {}
    constexpr int val() { return x; }
    constexpr void setMod(int _mod) { mod = _mod; }
    constexpr ModInt operator+ (const ModInt a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    constexpr ModInt operator- (const ModInt a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    constexpr ModInt operator* (const ModInt a) const { return ModInt(1LL * x * a.x % mod); }
    constexpr ModInt operator/ (const ModInt a) const { return *this * a.inv(); }
    constexpr bool operator== (const ModInt a) const { return x == a.x; };
    constexpr bool operator!= (const ModInt a) const { return x != a.x; };
    constexpr ModInt operator+= (const ModInt a) { x += a.x; if (x >= mod) x -= mod; return *this; }
    constexpr ModInt operator-= (const ModInt a) { x -= a.x; if (x < 0) x += mod; return *this; }
    constexpr ModInt operator*= (const ModInt a) { x = 1LL * x * a.x % mod; return *this; }
    constexpr ModInt operator/= (const ModInt a) { *this = *this / a; return *this; }
    constexpr friend ModInt operator+ (int y, const ModInt a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    constexpr friend ModInt operator- (int y, const ModInt a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    constexpr friend ModInt operator* (int y, const ModInt a){ return ModInt(1LL * y * a.x % mod);}
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
    static int mod;
    constexpr ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
};

constexpr int mod = 998244353;
template <const int T>
int ModInt<T>::mod = T;
using Mint = ModInt<mod>;


