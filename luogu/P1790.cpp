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
int a, b;
set<unsigned long long> s;
int getNum(int i, int j) { return (i - 1) * b + j - 1; }
bool vis[10][10];
bool cvis[10][10];

void print() {
    static int id = 1;
    std::clog << id++ << '\n';
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            std::clog << vis[i][j] << ' ';
        }
        std::clog << '\n';
    }
    std::clog << '\n';
}

int px[] = {1, -1, 0, 0};
int py[] = {0, 0, 1, -1};
void calc() {
    std::bitset<40> bit;
    int cnt = 0, tot = 0;
    int cx = 1, cy = 1;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (!vis[i][j]) {
                cx = i, cy = j;
                continue;
            }
            if (i == 1 or j == 1 or i == a or j == b) ++cnt;
            bit[getNum(i, j)] = 1;
            tot++;
        }
    }
    // if (cnt == a + a + b + b - 4) return;
    // std::queue<Pii> q;
    // q.emplace(cx, cy);
    // memcpy(cvis, vis, sizeof(vis));
    // while (!q.empty()) {
    //     auto [x, y] = q.front();
    //     q.pop();
    //     if (cvis[x][y]) continue;
    //     cvis[x][y] = 1;
    //     tot++;
    //     for (int i = 0; i < 4; ++i) {
    //         int rx = x + px[i];
    //         int ry = y + py[i];
    //         if (rx >= 1 and rx <= a and ry >= 1 and ry <= b) q.emplace(rx,
    //         ry);
    //     }
    // }
    // if (tot != a * b) return;
    s.insert(bit.to_ullong());
}

// void dfs(int x, int y) {
//     calc();
//     for (int i = 0; i < 4; ++i) {
//         int rx = x + px[i];
//         int ry = y + py[i];
//         if (rx >= 1 and rx <= a and ry >= 1 and ry <= b and !vis[rx][ry]) {
//             vis[rx][ry] = 1;
//             dfs(rx, ry);
//             vis[rx][ry] = 0;
//         }
//     }
// }
int ans = 0;
void dfs(int x, int y) {
    vis[x][y] = 1;
    if (x == 1 or x == a or y == 1 or y == b) {
        // calc();
        ++ans;
        vis[x][y] = 0;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int rx = x + px[i];
        int ry = y + py[i];
        if (rx >= 1 and rx <= a and ry >= 1 and ry <= b and !vis[rx][ry]) {
            // vis[rx][ry] = 1;
            dfs(rx, ry);
            // vis[rx][ry] = 0;
        }
    }
    vis[x][y] = 0;
}

int p[10][10];

void solve() {
    p[1][1] = 0;
    p[1][2] = 1;
    p[1][3] = 2;
    p[1][4] = 3;
    p[1][5] = 4;
    p[1][6] = 5;
    p[2][2] = 6;
    p[2][3] = 15;
    p[2][4] = 28;
    p[2][5] = 45;
    p[2][6] = 66;
    p[3][3] = 52;
    p[3][4] = 143;
    p[3][5] = 350;
    p[3][6] = 799;
    p[4][4] = 614;
    p[4][5] = 2431;
    p[4][6] = 9184;
    p[5][5] = 16000;
    p[5][6] = 102147;
    p[6][6] = 1114394;
    std::cin >> a >> b;
    // for (int i = 1; i <= a; ++i) {
    //     for (int j = 1; j <= b; ++j) {
    //         if (i == 1 or j == 1 or i == a or j == b) {
    //             vis[i][j] = 1;
    //             dfs(i, j);
    //             vis[i][j] = 0;
    //         }
    //     }
    // }
    // ++a, ++b;
    // for (int i = 2; i < a; ++i) {
    //     vis[i][1] = 1;
    //     dfs(i, 2);
    //     vis[i][1] = 0;
    // }
    // for (int i = 2; i < b; ++i) {
    //     vis[1][i] = 1;
    //     dfs(2, i);
    //     vis[1][i] = 0;
    // }
    // // std::cout << s.size() / 2 << '\n';
    // std::cout << ans << '\n';
    if (a > b) std::swap(a, b);
    std::cout << p[a][b];
}