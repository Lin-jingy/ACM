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
    void pushDown(int p, int l, int r) {
        if (!tag(p)) return;
        f(ls(p)) = tag(p);
        f(rs(p)) = tag(p);
        tag(ls(p)) = tag(p);
        tag(rs(p)) = tag(p);
        tag(p) ^= tag(p);
    }
    void pushUp(int p) {
        f(p) = f(ls(p)) | f(rs(p));
    }

public:
    SegmentTree(int n) {
        v.assign(n << 2, {});
    }
    void build(int p, int l, int r) {
        if (l == r) {
            f(p) = 2;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(p), l, mid);
        build(rs(p), mid + 1, r);
        pushUp(p);
    }
    void update(int p, int l, int r, int i, int j, int d) {
        if (i <= l and j >= r) {
            tag(p) = d;
            f(p) = d;
            return;
        }
        pushDown(p, l, r);
        int mid = (l + r) >> 1;
        if (i <= mid) update(ls(p), l, mid, i, j, d);
        if (j > mid) update(rs(p), mid + 1, r, i, j, d);
        pushUp(p);
    }
    int query(int p, int l, int r, int i, int j) {
        if (i <= l and j >= r) return f(p);
        pushDown(p, l, r);
        int mid = (l + r) >> 1, sum = 0;
        if (i <= mid) sum |= query(ls(p), l, mid, i, j);
        if (j > mid) sum |= query(rs(p), mid + 1, r, i, j);
        return sum;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k, q;
    std::cin >> n >> k >> q;

    SegmentTree T(n + 1);
    T.build(1, 1, n);
    while(q--) {
        char op;
        std::cin >> op;
        if(op == 'C') {
            int a, b, c;
            std::cin >> a >> b >> c;
            if(a > b) std::swap(a, b);
            T.update(1, 1, n, a, b, 1 << c);
        } else {
            int a, b;
            std::cin >> a >> b;
            if(a > b) std::swap(a, b);
            std::cout << __builtin_popcount(T.query(1, 1, n, a, b)) << '\n';
        }
    }


    return 0;
}