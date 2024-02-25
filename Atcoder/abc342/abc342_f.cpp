#include <bits/stdc++.h>

class SegmentTree {
private:
    struct Treenode {
        double f, tag;
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
        f(p) = f(ls(p)) + f(rs(p));
    }

public:
    SegmentTree(int n) {
        a.assign(n + 10, 0);
        v.assign(n << 3, {});
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
        int mid = l + r >> 1, sum = 0;
        if (i <= mid) sum += query(ls(p), l, mid, i, j);
        if (j > mid) sum += query(rs(p), mid + 1, r, i, j);
        return sum;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, l, d;
    std::cin >> n >> l >> d;
    double ans = 0;
    SegmentTree T(3 + n + 1);
    // T.build(1, 1, 3 * n);
    T.update(1, 1, 3 * n, 1, n, 1.0 / n);
    for(int i = 1; i < l; ++i) {
        T.update(1, 1, 3 * n, i + 1, i + 1 + n, T.query(1, 1, 3 * n, i, i));
    }
    for(int i = 1; i < l; ++i) {
        ans += T.query(1, 1, 3 * n, i, i);
    }
    printf("%.9lf", ans);


    return 0;
}