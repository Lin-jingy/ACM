#include <bits/stdc++.h>

template<const int T>
struct ModInt {
	int x;
	ModInt(int x = 0) : x(x % T) {}
	int val() { return x; }
	ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < T ? x0 : x0 - T); }
	ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + T : x0); }
	ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % T); }
	ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
	bool operator == (const ModInt &a) const { return x == a.x; };
	bool operator != (const ModInt &a) const { return x != a.x; };
	void operator += (const ModInt &a) { x += a.x; if (x >= T) x -= T; }
	void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += T; }
	void operator *= (const ModInt &a) { x = 1LL * x * a.x % T; }			
	void operator /= (const ModInt &a) { *this = *this / a; }
	friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < T ? x0 : x0 - T); }
	friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + T : x0); }			
	friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % T);}
	friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
	friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x;}
	friend std::istream &operator>>(std::istream &is, ModInt &t){return is >> t.x;}						
				
	ModInt pow(long long n) const {
        ModInt res(1), mul(x);
            while(n){
                if (n & 1) res *= mul;
                mul *= mul;
                n >>= 1;
            }
            return res;
	}
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
using mint = ModInt<mod>;


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    mint ans = n * (n + 1) / 2;
    int mx = 1e5;
    std::vector<mint> dp(2 * mx + 10);
    for(int i = 2; i < n; ++i) {
        auto last = dp;
        for(int j = 0; j <= mx + mx; ++j) 
            if(j - a[i] >= 0 and j - a[i] <= mx + mx) 
                dp[j] += last[j - a[i]];
            
        dp[a[i] + mx] += i - 1;
        ans += dp[mx];
    }

    std::cout << ans << '\n';

    return 0;
}