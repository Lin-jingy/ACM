#include <bits/stdc++.h>

template<const int T>
struct ModInt {
    // constexpr ModInt(int x) : x(x % T) {}
    constexpr ModInt(long long x) : x(x % T) {}
    constexpr ModInt() = default;
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

Mint p[(int)2e6 +5];
constexpr void init() {
    p[0] = 1;
    for(int i = 1; i < 2e6 + 5; ++i) p[i] = p[i - 1] * 10;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    int n;
    std::cin >> n;
    std::vector<std::pair<std::string, int>> v;
    Mint mulK = 1;
    std::vector<Mint> mul(n + 1);
    for(int i = 1; i <= n; ++i) {
        int k;
        std::cin >> k;
        mulK *= k;
        mul[i] = k;
        for(int j = 0; j < k; ++j) {
            std::string s;
            std::cin >> s;
            v.emplace_back(s, i);
        }
    }
    Mint sumk = mulK;
    Mint ans = 0;
    std::sort(v.begin(), v.end(), [](const std::pair<std::string, int> a, const std::pair<std::string, int> b) {
        return a.first + b.first < b.first + a.first;
    });
    int cnt = 0;
    for(auto [i, pos]:v) {
        Mint I = 0;
        for(auto j:i) I = I * 10 + j - '0';
        
        if(mul[pos] == 0) cnt--;
        else mulK /= mul[pos];

        if(cnt == 0) ans += I * mulK;

        mul[pos] += p[i.size()] - 1;
        if(mul[pos] == 0) cnt++;
        else mulK *= mul[pos];

    }

    std::cout << ans / sumk << '\n';

    return 0;
}