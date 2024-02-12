#include <bits/stdc++.h>

#define int long long
int mod;
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

class SegmentTree {
private:
    struct Treenode {
        int f, add, calc;
    };
    std::vector<Treenode> v;
    std::vector<int> a;
#define f(x) (v[x].f)
#define add(x) (v[x].add)
#define calc(x) (v[x].calc)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void pushDown(int p, int l, int r) {
        if (!add(p) and calc(p) == 1) return;
        int mid = l + r >> 1;
        f(ls(p)) = (f(ls(p)) * calc(p) % mod + add(p) * (mid - l + 1)) % mod;
        f(rs(p)) = (f(rs(p)) * calc(p) % mod + add(p) * (r - mid)) % mod;
        calc(ls(p)) = calc(ls(p)) * calc(p) % mod;
        calc(rs(p)) = calc(rs(p)) * calc(p) % mod;
        add(ls(p)) = (add(ls(p)) * calc(p) + add(p)) % mod;
        add(rs(p)) = (add(rs(p)) * calc(p) + add(p)) % mod;
        add(p) = 0, calc(p) = 1;
    }
    void pushUp(int p) {
        f(p) = (f(ls(p)) + f(rs(p))) % mod;
    }

public:
    SegmentTree(int n) {
        a.assign(n + 10, 0);
        v.assign(n << 3, {});
        for (int i = 1; i < (n << 3); ++i) calc(i) = 1;
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
            add(p) = (add(p) + d) % mod;
            f(p) = (f(p) + d * (r - l + 1)) % mod;
            return;
        }
        int mid = l + r >> 1;
        if (i <= mid) update(ls(p), l, mid, i, j, d);
        if (j > mid) update(rs(p), mid + 1, r, i, j, d);
        pushUp(p);
    }
    void update1(int p, int l, int r, int i, int j, int d) {
        pushDown(p, l, r);
        if (i <= l and j >= r) {
            add(p) = add(p) * d % mod;
            calc(p) = calc(p) * d % mod;
            f(p) = f(p) * d % mod;
            return;
        }
        int mid = l + r >> 1;
        if (i <= mid) update1(ls(p), l, mid, i, j, d);
        if (j > mid) update1(rs(p), mid + 1, r, i, j, d);
        pushUp(p);
    }
    int query(int p, int l, int r, int i, int j) {
        if (i <= l and j >= r) return f(p);
        pushDown(p, l, r);
        int mid = l + r >> 1, sum = 0;
        if (i <= mid) sum += query(ls(p), l, mid, i, j);
        if (j > mid) sum += query(rs(p), mid + 1, r, i, j);
        return sum % mod;
    }
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, q;
    std::cin >> n >> q >> mod;
    SegmentTree T(n + 10);
    T.input(n);
    T.build(1, 1, n);
    while (q--) {
        int op, x, y, k;
        std::cin >> op >> x >> y;
        if (op == 1) {
            std::cin >> k;
            T.update1(1, 1, n, x, y, k);
        } else if (op == 2) {
            std::cin >> k;
            T.update(1, 1, n, x, y, k);
        } else {
            std::cout << T.query(1, 1, n, x, y) << '\n';
        }
        dbg(T.query(1, 1, n, 1, n));
    }

    return 0;
}
