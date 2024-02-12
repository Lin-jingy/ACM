#include <bits/stdc++.h>
struct node {
    int f, tag;
    int ls, rs;
};

class SegmentTree {
private:
    node v[15000000];
    int f = 1;
#define ls(p) (v[p].ls)
#define rs(p) (v[p].rs)
#define f(p) (v[p].f)
#define tag(p) (v[p].tag)
    inline void push_up(int p) { f(p) = f(ls(p)) + f(rs(p)); }
    inline void addTag(int &p, int l, int r, int d) {  //?给节点p打上tag标记，并更新区间值
        if (!p) p = ++f, tag(f) = -1;
        if (d == -1) return;
        tag(p) = d;
        f(p) = d * (r - l + 1);
    }
    void push_down(int p, int l, int r) {  //?将tag传递给子树
        // 无法覆盖的情况
        int mid = l + r >> 1;
        addTag(ls(p), l, mid, tag(p));
        addTag(rs(p), mid + 1, r, tag(p));
        tag(p) = -1;  // 传递后自身标记清零
    }

    void update(int p, int l, int r, int i, int j, int d) {  //?区间[i, j]加d
        if (i <= l and r <= j) {
            addTag(p, l, r, d);
            return;
        }
        push_down(p, l, r);
        int mid = l + r >> 1;
        if (i <= mid) update(ls(p), l, mid, i, j, d);
        if (j > mid) update(rs(p), mid + 1, r, i, j, d);
        push_up(p);  // 更新当前区间值
    }
    int query(int p, int l, int r, int i, int j) {  //?查询[i,j]区间值
        if (l >= i and r <= j) return f(p);
        push_down(p, l, r);
        int mid = l + r >> 1;
        int res = 0;
        if (i <= mid) res += query(ls(p), l, mid, i, j);
        if (j > mid) res += query(rs(p), mid + 1, r, i, j);
        return res;
    }
} T;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;
    T.v[1].tag = -1;
    while (q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        if (k == 1)
            T.update(1, 1, n, l, r, 1);
        else
            T.update(1, 1, n, l, r, 0);
        std::cout << n - T.query(1, 1, n, 1, n) << '\n';
    }

    return 0;
}