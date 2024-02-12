#include <bits/stdc++.h>

class SegmentTree {
private:
    struct Treenode {
        int f, tag;
    };
    std::vector<Treenode> v;
#define f(x) (v[x].f)
#define tag(x) (v[x].tag)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void addTag(int p, int l, int r, int d) {
        tag(p) ^= d;
        f(p) = (r - l + 1) - f(p);
    }
    void pushDown(int p, int l, int r) {
        if (!tag(p)) return;
        int mid = l + r >> 1;
        addTag(ls(p), l, mid, tag(p));
        addTag(rs(p), mid + 1, r, tag(p));
        tag(p) = 0;
    }
    void pushUp(int p) {
        f(p) = f(ls(p)) + f(rs(p));
    }

public:
    std::vector<int> a;
    SegmentTree(int n) {
        a.assign(n + 10, 0);
        v.assign(n << 4, {});
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
            addTag(p, l, r, d);
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
        int mid = l + r >> 1, sum = 0;
        if (i <= mid) sum += query(ls(p), l, mid, i, j);
        if (j > mid) sum += query(rs(p), mid + 1, r, i, j);
        return sum;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    SegmentTree T(n);
    T.build(1, 1, n);
    while (m--) {
        int op, a, b;
        std::cin >> op >> a >> b;
        if (op == 0) {
            T.update(1, 1, n, a, b, 1);
            // std::cout << T.query(1, 1, n, 1, n) << '\n';
        } else {
            std::cout << T.query(1, 1, n, a, b) << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
