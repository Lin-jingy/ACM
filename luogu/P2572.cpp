#include <bits/stdc++.h>

#if __GNUC__
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <class _KEY, class _Compare = std::less<_KEY>>
using pbds_set =
    __gnu_pbds::tree<_KEY, __gnu_pbds::null_type, _Compare,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;
template <class _KEY, class _VALUE, class _Compare = std::less<_KEY>>
using pbds_map =
    __gnu_pbds::tree<_KEY, _VALUE, _Compare, __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;
template <class T, class Comp = std::less<T>>
using pbds_heap =
    __gnu_pbds::priority_queue<T, Comp, __gnu_pbds::pairing_heap_tag>;
#endif
#if __SIZEOF_POINTER__ == 8 && __GNUC__ && __cplusplus >= 202002L
using i128 = __int128;
std::istream &operator>>(std::istream &in, __int128 &value) {
    std::string s;
    in >> s;
    value = 0;
    bool op = 0;
    std::ranges::reverse(s);
    if (s.back() == '-') {
        op = 1;
        s.pop_back();
    }
    while (!s.empty()) value = value * 10 + s.back() - '0', s.pop_back();
    if (op) value = -value;
    return in;
}
std::ostream &operator<<(std::ostream &out, const __int128 &value) {
    __int128 x = (value < 0 ? -value : value);
    if (value < 0) out << '-';
    std::string s;
    while (x) {
        s += (char)(x % 10 + '0');
        x /= 10;
    }
    std::ranges::reverse(s);
    out << s;
    return out;
}
template <class... Args>
void print(const std::string_view &fmtStr, Args &&...args) {
    std::cout << std::vformat(fmtStr, std::make_format_args(args...));
}
#endif
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
#define RETURN(x)         \
    do {                  \
        return x, void(); \
    } while (0)
#define All(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define eb(x...) emplace_back(x)
#define fmt(x...) std::format(x)
#define logs(x...) Print_log(#x " ::", x) << std::endl
#define ensure(x)                                                        \
    if (!(x)) {                                                          \
        std::cerr << "ensure error:(" << #x << ")->at line:" << __LINE__ \
                  << std::endl;                                          \
        exit(-1);                                                        \
    }
constexpr int inf = INT_MAX;
constexpr long long INF = LONG_LONG_MAX;
template <class T>
using vec = vector<T>;
using str = std::string;
template <class K, class V>
using umap = std::unordered_map<K, V>;
template <class T>
using uset = std::unordered_set<T>;
using Pii = std::pair<int, int>;
template <class T>
using vvec = vector<vector<T>>;
template <class T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using max_heap = std::priority_queue<T>;
template <class T, size_t S>
using arr = std::array<T, S>;
template <class K, class V>
std::istream &operator>>(std::istream &in, std::pair<K, V> &v) {
    in >> v.first >> v.second;
    return in;
}
template <class K, class V>
std::ostream &operator<<(std::ostream &out, const std::pair<K, V> &v) {
    out << '{' << v.first << "," << v.second << '}';
    return out;
}
template <class T>
std::istream &operator>>(std::istream &in, std::vector<T> &v) {
    for (auto &i : v) in >> i;
    return in;
}
template <class T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    for (auto i = v.begin(); i != v.end(); ++i)
        out << *i << " \n"[i == v.end()];
    return out;
}
template <class T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s) {
    out << "\nsize:" << s.size() << '\n';
    for (auto i = s.begin(); i != s.end(); ++i)
        out << *i << " \n"[i == s.end()];
    return out;
}
template <class K, class V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &mp) {
    out << "\nsize:" << mp.size() << '\n';
    for (auto i = mp.begin(); i != mp.end(); ++i)
        out << '{' << i->first << "," << i->second << "}\n";
    return out;
}
template <class K, class V>
struct std::hash<std::pair<K, V>> {
    size_t operator()(const std::pair<K, V> &p) const {
        return std::hash<K>{}(p.first) ^ std::hash<V>{}(p.second);
    }
};
template <bool print = false>
class Timer {
   private:
    std::chrono::system_clock::time_point begin;

   public:
    Timer() { begin = std::chrono::system_clock::now(); }
    ~Timer() {
        if constexpr (print) {
            auto end = std::chrono::system_clock::now();
            auto time =
                std::chrono::duration<double, std::nano>(end - begin).count();
            std::clog << "\nThe program takes: " << time / 1e9 << " s\n";
        }
    }
    double get() {
        auto end = std::chrono::system_clock::now();
        auto time =
            std::chrono::duration<double, std::nano>(end - begin).count();
        return time / 1e9;
    }
};
template <class... Ts>
auto &Print_log(Ts... ts) {
    return ((std::clog << ts << " "), ...);
}
void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    vec<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    vec<int> fl0(n << 2), fl1(n << 2), fr0(n << 2), fr1(n << 2);
    vec<int> f0(n << 2), f1(n << 2);
    vec<int> c0(n << 2), c1(n << 2), tag(n << 2);
#define ls (p << 1)
#define rs (p << 1 | 1)
    auto pushUp = [&](int p) {
        if (c1[ls] == 0) fl0[p] = fl0[ls] + fl0[rs];
        else
            fl0[p] = fl0[ls];
        if (c1[rs] == 0) fr0[p] = fr0[rs] + fr0[ls];
        else
            fr0[p] = fr0[rs];

        if (c0[ls] == 0) fl1[p] = fl1[ls] + fl1[rs];
        else
            fl1[p] = fl1[ls];
        if (c0[rs] == 0) fr1[p] = fr1[rs] + fr1[ls];
        else
            fr1[p] = fr1[rs];

        f0[p] = std::max({f0[ls], f0[rs], fr0[ls] + fl0[rs]});
        f1[p] = std::max({f1[ls], f1[rs], fr1[ls] + fl1[rs]});
        c0[p] = c0[ls] + c0[rs];
        c1[p] = c1[ls] + c1[rs];
    };
    auto pushDown = [&](int p, int l, int r) {
        if (!tag[p]) return;
        tag[ls] = tag[rs] = tag[p];
        int mid = (l + r) >> 1;
        if (tag[p] == 1) {
            fl0[ls] = fr0[ls] = f0[ls] = c0[ls] = 0;
            fl1[ls] = fr1[ls] = f1[ls] = c1[ls] = mid - l + 1;
        } else if (tag[p] == -1) {
            fl0[rs] = fr0[rs] = f0[rs] = c0[rs] = r - mid;
            fl1[rs] = fr1[rs] = f1[rs] = c1[rs] = 0;
        }
        tag[p] = 0;
    };
    auto build = [&](auto self, int p, int l, int r) -> void {
        if (l == r) {
            if (a[l] == 0) fl0[p] = fr0[p] = f0[p] = c0[p] = 1;
            else
                fl1[p] = fr1[p] = f1[p] = c1[p] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        self(self, ls, l, mid);
        self(self, rs, mid + 1, r);
        pushUp(p);
    };
    auto set = [&](auto self, int p, int l, int r, int i, int j,
                   int val) -> void {
        if (i <= l and j >= r) {
            if (val == 1) {
                tag[p] = 1;
                fl0[p] = fr0[p] = f0[p] = c0[p] = 0;
                fl1[p] = fr1[p] = f1[0] = c1[p] = r - l + 1;
            } else {
                tag[p] = -1;
                fl0[p] = fr0[p] = f0[p] = c0[p] = r - l + 1;
                fl1[p] = fr1[p] = f1[0] = c1[p] = 0;
            }
            return;
        }
        pushDown(p, l, r);
        int mid = (l + r) >> 1;
        if (i <= mid) self(self, ls, l, mid, i, j, val);
        if (j > mid) self(self, rs, mid + 1, r, i, j, val);
        pushUp(p);
    };
    auto reverse = [&](auto self, int p, int l, int r, int i, int j) -> void {
        if (l == r) return;
        if (i <= l and j >= r) {
            std::swap(fl0[p], fl1[p]);
            std::swap(fr0[p], fr1[p]);
            std::swap(f0[p], f1[p]);
            std::swap(c0[p], c1[p]);
        }
        pushDown(p, l, r);
        int mid = (l + r) >> 1;
        if (i <= mid) self(self, ls, l, mid, i, j);
        if (j > mid) self(self, rs, mid + 1, r, i, j);
        pushUp(p);
    };
    auto queryTot = [&](auto self, int p, int l, int r, int i, int j) -> int {
        if (i <= l and j >= r) return c1[p];
        pushDown(p, l, r);
        int mid = (l + r) >> 1;
        int tot = 0;
        if (i <= mid) tot += self(self, ls, l, mid, i, j);
        if (j > mid) tot += self(self, rs, mid + 1, r, i, j);
        return tot;
    };
    auto queryMax = [&](auto self, int p, int l, int r, int i, int j) -> int {
        if (i <= l and j >= r) return f1[p];
        pushDown(p, l, r);
        int mid = (l + r) >> 1;
        int max = 0;
        if (i <= mid) max = self(self, ls, l, mid, i, j);
        if (j > mid) max = std::max(max, self(self, rs, mid + 1, r, i, j));
        return max;
    };
#undef ls
#undef rs
    build(build, 1, 1, n);
    while (m--) {
        int op, l, r;
        std::cin >> op >> l >> r;
        ++l, ++r;
        if (op == 0) set(set, 1, 1, n, l, r, 0);
        else if (op == 1)
            set(set, 1, 1, n, l, r, 1);
        else if (op == 2)
            reverse(reverse, 1, 1, n, l, r);
        else if (op == 3)
            std::cout << queryTot(queryTot, 1, 1, n, l, r) << '\n';
        else
            std::cout << queryMax(queryMax, 1, 1, n, l, r) << '\n';
    }
}