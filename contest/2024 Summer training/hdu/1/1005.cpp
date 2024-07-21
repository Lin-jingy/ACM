#include <bits/stdc++.h>
#include <numeric>

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
constexpr int mod = 998244353;
using Mint = ModInt<mod>;
constexpr int N = 1e7 + 1;
Mint p[N];
constexpr void init() {
    p[0] = 1;
    for(int i = 1; i < N; ++i) p[i] = p[i - 1] * i;
}
constexpr Mint A(int a, int b) {
    return p[a] / p[b];
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(26);
    for(int i = 0; i < n; ++i) {
        char op;
        int x;
        std::cin >> op >> x;
        v[op - 'a'] += x;
    }
    int sum = std::accumulate(v.begin(), v.end(), 0);

    int k = sum / 2;
    if(sum % 2 == 0) {
        Mint ans = p[k] / p[sum];
        for(int i = 0; i < 26; ++i) {
            if(v[i] % 2 != 0) goto A;
            ans *= A(v[i], v[i] / 2);
        }
        ans = (Mint(1) - ans) / Mint(2);
        std::cout << ans << '\n';
        return ;
        A:;
        std::cout << Mint(1) / Mint(2) << '\n';
    } else {
        int add = 0;
        Mint ans = 1;
        for(int i = 0; i < 26; ++i) {
            if(v[i] % 2 != 0) ++add;
            ans *= A(v[i], v[i] / 2);
        }
        ans = (Mint(1) + ans * p[k] / p[sum]) / Mint(2);
        if(add == 1) {
            std::cout << ans << '\n';
        } else {
            std::cout << Mint(1) / Mint(2) << '\n';
        }
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}