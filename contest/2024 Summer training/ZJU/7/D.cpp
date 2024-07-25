#include <bits/stdc++.h>

enum OPTION {
    Nature,
    Single,
    Double,
};
template <enum OPTION op, int base1 = 131, int base2 = 133331>
class StringHash {
    #define int long long 
private:
    std::vector<int> hash1, hash2, p1, p2;
    int mod1;
    int mod2;
    bool isprime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }
    int findPrime(int n) {
        while (!isprime(n)) n++;
        return n;
    }
    void init_nature(const std::string &s) {
        p1[0] = hash1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hash1[i] = hash1[i - 1] * base1 + s[i - 1];
            p1[i] = p1[i - 1] * base1;
        }
    }
    void init_single(const std::string &s) {
        p1[0] = hash1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hash1[i] = (1LL * hash1[i - 1] * base1 + s[i - 1]) % mod1;
            p1[i] = 1LL * p1[i - 1] * base1 % mod1;
        }
    }
    void init_double(const std::string &s) {
        hash2.resize(s.size() + 1);
        p2.resize(s.size() + 1);
        p1[0] = p2[0] = hash1[0] = hash2[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hash1[i] = (1LL * hash1[i - 1] * base1 + s[i - 1]) % mod1;
            hash2[i] = (1LL * hash2[i - 1] * base2 + s[i - 1]) % mod2;
            p1[i] = 1LL * p1[i - 1] * base1 % mod1;
            p2[i] = 1LL * p2[i - 1] * base2 % mod2;
        }
    }
    void init_mod() {
        static int MOD1 = 0, MOD2 = 0;
        if(!MOD1) {
            std::mt19937_64 rnd(time(0));
            MOD1 = findPrime(rnd() % 900'000'000 + 100'000'000);
            MOD2 = findPrime(rnd() % 900'000'000 + 100'000'000);
        }
        mod1 = MOD1; mod2 = MOD2;
    }
public:
    StringHash(const std::string &s): hash1(s.size() + 1), p1(s.size() + 1){
        init_mod();
        if constexpr (op == Nature) init_nature(s);
        if constexpr (op == Single) init_single(s);
        if constexpr (op == Double) init_double(s);
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Nature, int> get(int l, int r) {
        ++l, ++r;
        return hash1[r] - hash1[l - 1] * p1[r - l + 1];
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Single, int> get(int l, int r) {
        ++l, ++r;
        return (hash1[r] + (mod1 - hash1[l - 1]) * p1[r - l + 1]) % mod1;
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Double, std::pair<int, int>> get(int l, int r) {
        ++l, ++r;
        return {(hash1[r] + 1LL * (mod1 - hash1[l - 1]) * p1[r - l + 1]) % mod1,
        (hash2[r] + 1LL * (mod2 - hash2[l - 1]) * p2[r - l + 1]) % mod2};
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Nature || O == Single, int> getAll() {
        return hash1.back();
    }
    template <enum OPTION O = op>
    std::enable_if_t<O == Double, std::pair<int, int>> getAll() {
        return {hash1.back(), hash2.back()};
    }
    #undef int
};


template<const int T>
struct ModInt {
	constexpr ModInt(int x = 0) : x(x % T) {}
	constexpr int val() { return x; }
	constexpr ModInt operator+ (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < T ? x0 : x0 - T); }
	constexpr ModInt operator- (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + T : x0); }
	constexpr ModInt operator* (const ModInt &a) const { return ModInt(1LL * x * a.x % T); }
	constexpr ModInt operator/ (const ModInt &a) const { return *this * a.inv(); }
	constexpr bool operator== (const ModInt &a) const { return x == a.x; };
	constexpr bool operator!= (const ModInt &a) const { return x != a.x; };
	constexpr void operator+= (const ModInt &a) { x += a.x; if (x >= T) x -= T; }
	constexpr void operator-= (const ModInt &a) { x -= a.x; if (x < 0) x += T; }
	constexpr void operator*= (const ModInt &a) { x = 1LL * x * a.x % T; }			
	constexpr void operator/= (const ModInt &a) { *this = *this / a; }
	constexpr friend ModInt operator+ (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < T ? x0 : x0 - T); }
	constexpr friend ModInt operator- (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + T : x0); }			
	constexpr friend ModInt operator* (int y, const ModInt &a){ return ModInt(1LL * y * a.x % T);}
	constexpr friend ModInt operator/ (int y, const ModInt &a){ return ModInt(y) / a;}
	constexpr friend std::ostream &operator<< (std::ostream &os, const ModInt &a) { return os << a.x;}
	constexpr friend std::istream &operator>> (std::istream &is, ModInt &t){return is >> t.x;}						
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
	int x;
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


void solve() {
    std::string s, rs;
    std::cin >> s;
    int n = s.size();
    rs = s;
    std::reverse(rs.begin(), rs.end());
    Mint ans = 0;
    StringHash<Single> X(s), Y(rs);
    Mint last = 0;
    for(int i = 0; i < n; ++i) {
        
        if(i % 2 == 0) last = last * 26 + s[i / 2] - 'a';
        ans += last;

        if(X.get(0, i) == Y.get(n - i - 1, n - 1)) {
            ans += 1;
        } else {
            if(i % 2 == 0) {
                int l = 0, r = i / 2, pos = 0;
                int M = i / 2, M1 = n - 1 - M;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(X.get(M - mid, M + mid) == Y.get(M1 - mid, M1 + mid)) l = mid + 1, pos = mid;
                    else r = mid - 1;
                }
                if(s[M - pos - 1] < s[M + pos + 1]) ans += 1;
            } else {
                int l = 0, r = i / 2, pos = -1;
                int M = i / 2, M1 = n - 1 - M;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(X.get(M - mid, M + mid + 1) == Y.get(M1 - mid - 1, M1 + mid)) l = mid + 1,  pos = mid;
                    else r = mid - 1;
                }
                if(s[M - pos - 1] < s[M + pos + 2]) ans += 1;
            }
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}