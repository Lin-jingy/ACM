#include <bits/stdc++.h>

#define int long long

class SegmentTree {
private:
    struct Treenode {
        int f, k, d;
    };
    std::vector<Treenode> v;
#define f(x) (v[x].f)
#define k(x) (v[x].k)
#define d(x) (v[x].d)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void addTag(int p, int l, int r, int k, int d) {
        k(p) += k, d(p) += d;
        f(p) += (r - l + 1) * (k + (r - l) * d + k) / 2;
    }
    void pushDown(int p, int l, int r) {
        if (!k(p) and !d(p)) return;
        int mid = l + r >> 1;
        addTag(ls(p), l, mid, k(p), d(p));
        addTag(rs(p), mid + 1, r, k(p) + (mid - l + 1) * d(p), d(p));
        k(p) = d(p) = 0;
    }
    void pushUp(int p) {
        f(p) = f(ls(p)) + f(rs(p));
    }

public:
    std::vector<int> a;
    SegmentTree(int n) {
        a.assign(n + 10, 0);
        v.assign(n << 2, {});
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
    void update(int p, int l, int r, int i, int j, int k, int d) {
        pushDown(p, l, r);
        if (i == l and j == r) {
            addTag(p, l, r, k, d);
            return;
        }
        int mid = l + r >> 1;
        if (i <= mid) update(ls(p), l, mid, i, mid, k, d);
        if (j > mid) update(rs(p), mid + 1, r, mid + 1, j, k + (mid - i + 1) * d, d);
        pushUp(p);
    }
    int query(int p, int l, int r, int i, int j) {
        if (i <= l and j >= r) return f(p);
        pushDown(p, l, r);
        int mid = l + r >> 1, sum = 0;
        if (i <= mid) sum += query(ls(p), l, mid, i, j);
        if (j > mid) sum += query(rs(p), mid + 1, r, i, j);
        return sum;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    SegmentTree T(n + 10);
    for (int i = 1; i <= n; ++i) std::cin >> T.a[i];
    T.build(1, 1, n);
    while (m--) {
        int op, l, r, k, d, p;
        std::cin >> op;
        if (op == 1) {
            std::cin >> l >> r >> k >> d;
            T.update(1, 1, n, l, r, k, d);
        } else {
            std::cin >> p;
            std::cout << T.query(1, 1, n, p, p) << '\n';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}
