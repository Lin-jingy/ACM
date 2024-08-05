#include <bits/stdc++.h>

#define int long long

template <class T, class A = std::allocator<T>>
class vector : public std::vector<T, A> {
   public:
    constexpr vector() noexcept(noexcept(A())) : std::vector<T, A>() {}
    constexpr explicit vector(const A &alloc) noexcept
        : std::vector<T, A>(alloc) {}
    constexpr vector(size_t count, const T &value = T(), const A &alloc = A())
        : std::vector<T, A>(count, value, alloc) {}
    template <class InputIt>
    constexpr vector(InputIt first, InputIt last, const A &alloc = A())
        : std::vector<T, A>(first, last, alloc) {}
    constexpr vector(const vector &other, const A &alloc = A())
        : std::vector<T, A>(other, alloc) {}
    constexpr vector(vector &&other, const A &alloc = A())
        : std::vector<T, A>(other, alloc) {}
    constexpr vector(std::initializer_list<T> init, const A &alloc = A())
        : std::vector<T, A>(init, alloc) {}
    constexpr T &operator[](size_t pos) { return this->at(pos); }
    constexpr const T &operator[](size_t pos) const { return this->at(pos); }
};
using namespace std;
template <const int T>
struct ModInt {
    const static int mod = T;
    long long x;
    ModInt(int x = 0) : x(x % mod) {}
    //	ModInt(long long x) : x(x % mod) {}
    int val() { return x; }
    ModInt operator+(const ModInt &a) const {
        int x0 = x + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    ModInt operator-(const ModInt &a) const {
        int x0 = x - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    ModInt operator*(const ModInt &a) const {
        return ModInt(1LL * x * a.x % mod);
    }
    ModInt operator/(const ModInt &a) const { return *this * a.inv(); }
    bool operator==(const ModInt &a) const { return x == a.x; };
    bool operator!=(const ModInt &a) const { return x != a.x; };
    void operator+=(const ModInt &a) {
        x += a.x;
        if (x >= mod) x -= mod;
    }
    void operator-=(const ModInt &a) {
        x -= a.x;
        if (x < 0) x += mod;
    }
    void operator*=(const ModInt &a) { x = 1LL * x * a.x % mod; }
    void operator/=(const ModInt &a) { *this = *this / a; }
    friend ModInt operator+(int y, const ModInt &a) {
        int x0 = y + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    friend ModInt operator-(int y, const ModInt &a) {
        int x0 = y - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    friend ModInt operator*(int y, const ModInt &a) {
        return ModInt(1LL * y * a.x % mod);
    }
    friend ModInt operator/(int y, const ModInt &a) { return ModInt(y) / a; }
    friend ostream &operator<<(ostream &os, const ModInt &a) {
        return os << a.x;
    }
    friend istream &operator>>(istream &is, ModInt &t) { return is >> t.x; }

    ModInt pow(long long n) const {
        ModInt res(1), mul(x);
        while (n) {
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
};
constexpr int mod = 998244353;
using mint = ModInt<mod>;
const int N = 1e5 + 10;
::vector<int> idx(N), f(N);
::vector<mint> dp(N);
::vector<int> g[N];

void dfs(int u, int fa) {
    dp[u] = 1;
    f[u] = fa;
    for (auto x : g[u]) {
        if (x == fa) continue;
        dfs(x, u);
        dp[u] *= (dp[x] + 1);
    }
}

void init(int t) {
    for (int i = 1; i <= t; i++) {
        dp[i] = 1;
        g[i].clear();
    }
}
void sl() {
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        idx[i] = num;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[idx[u]].push_back(idx[v]);
        g[idx[v]].push_back(idx[u]);
    }
    dfs(0, 0);
    ::vector<int> vis(n + 1);
    vis[0] = 1;
    mint sum = dp[0], now = dp[0];
    for (int i = 1; i < n; i++) {
        int u = i;
        if (!vis[u]) {
            ::vector<int> pt;
            while (!vis[u]) {
                pt.push_back(u);
                u = f[u];
            }
            for (int j = (int)pt.size() - 1; j >= 0; j--) {
                vis[pt[j]] = 1;
                now /= (dp[pt[j]] + 1);
                now *= dp[pt[j]];
            }
        }
        sum += now;
    }
    cout << sum << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sl();
    return 0;
}