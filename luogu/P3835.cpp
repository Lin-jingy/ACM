#include <bits/stdc++.h>

#if __GNUC__
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
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
template <class T>
using rope = __gnu_cxx::rope<T>;
#endif
template <class K, class V>
std::istream &operator>>(std::istream &in, std::pair<K, V> &v);
template <class K, class V>
std::ostream &operator<<(std::ostream &out, const std::pair<K, V> &v);
template <class T>
std::istream &operator>>(std::istream &in, std::vector<T> &v);
template <class T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v);
template <class T, size_t size>
std::istream &operator>>(std::istream &in, std::array<T, size> &v);
template <class T, size_t size>
std::ostream &operator<<(std::ostream &out, const std::array<T, size> &v);
template <class T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s);
template <class K, class V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &mp);
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
using vec = std::vector<T>;
using str = std::string;
template <class K, class V>
using umap = std::unordered_map<K, V>;
template <class T>
using uset = std::unordered_set<T>;
using Pii = std::pair<int, int>;
template <class T>
using vvec = std::vector<std::vector<T>>;
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
template <class T, size_t size>
std::istream &operator>>(std::istream &in, std::array<T, size> &v) {
    for (auto &i : v) in >> i;
    return in;
}
template <class T, size_t size>
std::ostream &operator<<(std::ostream &out, const std::array<T, size> &v) {
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
using std::map;  // NOLINT(misc-unused-using-decls)
using std::set;  // NOLINT(misc-unused-using-decls)
void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

class LastingTree {
   private:
    struct node {
        int num = 0, l, r;
    };
    vec<node> f;
    int tot = 0;

   public:
    LastingTree(int n) : f(n << 5), tot(n + 10) {}
    void insert(int last, int now, int val, int l, int r) {
        if (l == r) return f[now].num = f[last].num + 1, void();
        int mid = (l + r) >> 1;
        f[now] = f[last];
        f[now].num++;
        if (val <= mid)
            f[now].l = ++tot, insert(f[last].l, f[now].l, val, l, mid);
        else f[now].r = ++tot, insert(f[last].r, f[now].r, val, mid + 1, r);
    }
    void del(int last, int now, int val, int l, int r) {
        if (l == r) return f[now].num = std::max(0, f[last].num - 1), void();
        int mid = (l + r) >> 1;
        f[now] = f[last];
        f[now].num--;
        if (val <= mid) f[now].l = ++tot, del(f[last].l, f[now].l, val, l, mid);
        else f[now].r = ++tot, del(f[last].r, f[now].r, val, mid + 1, r);
    }
    int askXRand(int version, int x, int l, int r) {  // 查询x的排名
        if (l == r) return 1;
        int mid = (l + r) >> 1;
        if (x <= mid) return askXRand(f[version].l, x, l, mid);
        else return f[f[version].l].num + askXRand(f[version].r, x, mid + 1, r);
    }
    int askRandX(int version, int x, int l, int r) {  // 查询排名为x的数
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (f[f[version].l].num >= x) return askRandX(f[version].l, x, l, mid);
        else return askRandX(f[version].r, x - f[f[version].l].num, mid + 1, r);
    }
    int askMaxBeforeX(int version, int l, int r, int x) {
        if (l == r) return f[version].num ? l : INT_MIN + 2;
        if (f[version].num == 0) return INT_MIN + 2;
        int mid = (l + r) >> 1;
        if (x <= mid) {
            return askMaxBeforeX(f[version].l, l, mid, x);
        } else {
            return std::max(askMaxBeforeX(f[version].l, l, mid, x),
                            askMaxBeforeX(f[version].r, mid + 1, r, x));
        }
    }
    int askMinAfterX(int version, int l, int r, int x) {
        if (l == r) return f[version].num ? l : INT_MAX;
        if (f[version].num == 0) return INT_MAX;
        int mid = (l + r) >> 1;
        if (x > mid) {
            return askMinAfterX(f[version].r, mid + 1, r, x);
        } else {
            return std::min(askMinAfterX(f[version].l, l, mid, x),
                            askMinAfterX(f[version].r, mid + 1, r, x));
        }
    }
};

void solve() {
    // Timer<1> _;
    // freopen("C:/Users/sugon/Desktop/ACM/P3835_19.in", "r", stdin);
    // freopen("C:/Users/sugon/Desktop/ACM/1.out", "w", stdout);
    int n;
    std::cin >> n;
    vec<arr<int, 3>> v(n + 1);
    vec<int> mp;
    for (int i = 1; i <= n; ++i) {
        std::cin >> v[i];
        if (v[1][1] != 4) mp.eb(v[i][2]);
    }
    std::ranges::sort(mp);
    mp.erase(std::unique(All(mp)), mp.end());
    mp.insert(mp.begin(), INT_MIN);
    auto get = [&](int x) -> int {
        return std::ranges::lower_bound(mp, x) - mp.begin();
    };
    int N = static_cast<int>(mp.size()) - 1;
    LastingTree T(mp.size() + 100);
    vec<int> V(n + 1);
    auto find = [&](auto self, int p) -> int {
        return V[p] == p ? p : V[p] = self(self, V[p]);
    };
    std::iota(All(V), 0);
    for (int i = 1; i <= n; ++i) {
        auto [version, op, x] = v[i];
        if (op == 1) T.insert(find(find, version), i, get(x), 1, N);
        else if (op == 2) T.del(find(find, version), i, get(x), 1, N);
        else if (op == 3) {
            V[i] = version;
            std::cout << T.askXRand(find(find, version), get(x), 1, N) << '\n';
        } else if (op == 4) {
            V[i] = version;
            std::cout << mp[T.askRandX(find(find, version), x, 1, N)] << '\n';
        } else if (op == 5) {
            V[i] = version;
            if (get(x) == 1) {
                std::cout << INT_MIN + 2 << '\n';
                continue;
            }
            int ans = T.askMaxBeforeX(find(find, version), 1, N, get(x) - 1);
            if (ans == INT_MIN + 2) std::cout << ans << '\n';
            else std::cout << mp[ans] << '\n';
        } else {
            V[i] = version;
            if (get(x) == N) {
                std::cout << INT_MAX << '\n';
                continue;
            }
            int ans = T.askMinAfterX(find(find, version), 1, N, get(x) + 1);
            if (ans == INT_MAX) std::cout << ans << '\n';
            else std::cout << mp[ans] << '\n';
        }
    }
}