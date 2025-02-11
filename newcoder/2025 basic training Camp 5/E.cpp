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
    if (s.empty()) s += '0';
    out << s;
    return out;
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
#define int long long
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
    std::cin >> T;
    while (T--) solve();
    return 0;
}

char v[5][5];

void solve() {
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            std::cin >> v[i][j];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= 3; ++i) {
        cnt += std::count(v[i] + 1, v[i] + 4, 'X');
    }

    if (cnt <= 2) RETURN(std::cout << "Yes\n");

    for (int i = 1; i <= 3; ++i) {
        int cnt1 = 0, cnt0 = 0;
        for (int j = 1; j <= 3; ++j)
            if (v[i][j] == 'X') ++cnt1;
            else if (v[i][j] == 'G') ++cnt0;
        if (cnt1 >= 1 && cnt1 + cnt0 == 3) RETURN(std::cout << "Yes\n");
    }

    for (int i = 1; i <= 3; ++i) {
        int cnt1 = 0, cnt0 = 0;
        for (int j = 1; j <= 3; ++j)
            if (v[j][i] == 'X') ++cnt1;
            else if (v[j][i] == 'G') ++cnt0;
        if (cnt1 >= 1 && cnt1 + cnt0 == 3) RETURN(std::cout << "Yes\n");
    }

    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= 3; ++i)
        if (v[i][i] == 'X') ++cnt1;
        else if (v[i][i] == 'G') ++cnt0;
    if (cnt1 >= 1 && cnt1 + cnt0 == 3) RETURN(std::cout << "Yes\n");

    cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= 3; ++i)
        if (v[i][4 - i] == 'X') ++cnt1;
        else if (v[i][4 - i] == 'G') ++cnt0;
    if (cnt1 >= 1 && cnt1 + cnt0 == 3) RETURN(std::cout << "Yes\n");

    std::cout << "No\n";
}