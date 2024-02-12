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

class SegmentTree {
private:
    struct Treenode {
        int f, tag, set;
    };
#define f(x) (v[x].f)
#define tag(x) (v[x].tag)
#define set(x) (v[x].set)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void addTag(int p, int l, int r, int d) {
        tag(p) += d;
        f(p) += d;
    }
    void addSet(int p, int l, int r, int d) {
        set(p) = d;
        tag(p) = 0;
        f(p) = set(p);
    }
    void pushDown(int p, int l, int r) {
        int mid = l + r >> 1;
        if (set(p) != LONG_LONG_MIN) {
            addSet(ls(p), l, mid, set(p));
            addSet(rs(p), mid + 1, r, set(p));
            set(p) = LONG_LONG_MIN;
        }
        if (!tag(p)) return;
        addTag(ls(p), l, mid, tag(p));
        addTag(rs(p), mid + 1, r, tag(p));
        tag(p) = 0;
    }
    void pushUp(int p) {
        f(p) = std::max(f(ls(p)), f(rs(p)));
    }

public:
    std::vector<int> a;
    std::vector<Treenode> v;
    SegmentTree(int n) {
        a.assign(n + 1000, 0);
        v.assign(n << 3, {});
        for (int i = 0; i <= n; ++i) f(i) = LONG_LONG_MIN;
    }
    void build(int p, int l, int r) {
        set(p) = LONG_LONG_MIN;
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
            addTag(p, l, r, d);
            return;
        }
        int mid = l + r >> 1;
        if (i <= mid) update(ls(p), l, mid, i, j, d);
        if (j > mid) update(rs(p), mid + 1, r, i, j, d);
        pushUp(p);
    }
    void Set(int p, int l, int r, int i, int j, int d) {
        dbg("set", l, r, set(p));
        pushDown(p, l, r);
        if (i <= l and j >= r) {
            addSet(p, l, r, d);
            return;
        }
        int mid = l + r >> 1;
        if (i <= mid) Set(ls(p), l, mid, i, j, d);
        if (j > mid) Set(rs(p), mid + 1, r, i, j, d);
        pushUp(p);
    }
    int query(int p, int l, int r, int i, int j) {
        dbg("query", l, r, set(p));
        if (i <= l and j >= r) return f(p);
        pushDown(p, l, r);
        int mid = l + r >> 1, mx = LONG_LONG_MIN;
        if (i <= mid) mx = std::max(query(ls(p), l, mid, i, j), mx);
        if (j > mid) mx = std::max(query(rs(p), mid + 1, r, i, j), mx);
        return mx;
    }
};

void solve() {
    int n, q;
    std::cin >> n >> q;
    SegmentTree T(n + 10);
    for (int i = 1; i <= n; ++i) std::cin >> T.a[i];
    T.build(1, 1, n);
    while (q--) {
        int op, l, r, x;
        std::cin >> op >> l >> r;
        if (op == 1) {
            std::cin >> x;
            T.Set(1, 1, n, l, r, x);
        } else if (op == 2) {
            std::cin >> x;
            T.update(1, 1, n, l, r, x);
        } else {
            std::cout << T.query(1, 1, n, l, r) << '\n';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
