#include <bits/stdc++.h>

#define LOCAL 0
#if LOCAL
#define dbg(x...)                  \
    do {                           \
        std::cout << #x << " -> "; \
        err(x);                    \
    } while (0)

void err() {
    std::cout << std::endl
              << std::endl;
}

template <class T, class... Ts>
void err(T arg, Ts... args) {
    std::cout << std::fixed << std::setprecision(10) << arg << ' ';
    err(args...);
}
#else
#define dbg(...)
#endif
#define int long long
using PII = std::pair<int, int>;
using i128 = __int128;
#define All(x) x.begin(), x.end()
#define eb(x) emplace_back(x)
using vec = std::vector<int>;
void solve();
class SegmentTree {
private:
    struct Treenode {
        int f, tag;
    };
    std::vector<Treenode> v;
    std::vector<int> a;
#define f(x) (v[x].f)
#define tag(x) (v[x].tag)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void pushDown(int p, int l, int r) {
        if (!tag(p)) return;
        int mid = l + r >> 1;
        f(ls(p)) += tag(p) * (mid - l + 1);
        f(rs(p)) += tag(p) * (r - mid);
        tag(ls(p)) += tag(p);
        tag(rs(p)) += tag(p);
        tag(p) = 0;
    }
    void pushUp(int p) {
        f(p) = std::min(f(ls(p)), f(rs(p)));
    }

public:
    SegmentTree(int n) {
        a.assign(n + 10, 0);
        v.assign(n << 3, {});
    }
    void input(int n) {
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
    }
    void build(int p, int l, int r) {
        if (l == r) {
            f(p) = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(ls(p), l, mid);
        build(rs(p), mid + 1, r);
        pushUp(p);
    }
    void update(int p, int l, int r, int i, int j, int d) {
        pushDown(p, l, r);
        if (i <= l and j >= r) {
            tag(p) = tag(p) + d;
            f(p) = f(p) + d * (r - l + 1);
            return;
        }
        int mid = l + r >> 1;
        if (i <= mid) update(ls(p), l, mid, i, j, d);
        if (j > mid) update(rs(p), mid + 1, r, i, j, d);
        pushUp(p);
    }
    int query(int p, int l, int r, int i, int j) {
        if (i <= l and j >= r) return f(p);
        pushDown(p, l, r);
        int mid = l + r >> 1, sum = LONG_LONG_MAX;
        if (i <= mid) sum = query(ls(p), l, mid, i, j);
        if (j > mid) sum = std::min(sum, query(rs(p), mid + 1, r, i, j));
        return sum;
    }
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    SegmentTree T(n + 10);
    T.input(n);
    T.build(1, 1, n);
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << T.query(1, 1, n, l, r) << ' ';
    }
}