#include <bits/stdc++.h>

const int N = 1e6 + 5;
int a[N];

class Persistable_Segment_Tree {
private:
    int f = 0;
    struct node {
        int val, ls, rs;
    } treeNode[N << 5];
#define ls(x) (treeNode[x].ls)
#define rs(x) (treeNode[x].rs)
#define val(x) (treeNode[x].val)
public:
    int his[N << 5];
    void build(int &p, int l, int r) {
        p = ++f;
        if (l == r) {
            val(p) = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(ls(p), l, mid);
        build(rs(p), mid + 1, r);
    }
    void ins(int &p, int pre, int l, int r, int q, int v) {
        // p为当前版本号, pre为历史版本号, l、r为查询区间, q为要更改的位置, v为要更改为的值
        p = ++f;
        ls(p) = ls(pre);
        rs(p) = rs(pre);
        val(p) = val(pre);
        if (l == r) {
            val(p) = v;
            return;
        }
        int mid = (l + r) >> 1;
        if (q <= mid)
            ins(ls(p), ls(pre), l, mid, q, v);
        else
            ins(rs(p), rs(pre), mid + 1, r, q, v);
    }
    int query(int p, int l, int r, int q) {
        // p为当前版本号, l、r为查询区间, q为需要查询的位置
        if (l == r) return val(p);
        int mid = (l + r) >> 1;
        if (q <= mid)
            return query(ls(p), l, mid, q);
        else
            return query(rs(p), mid + 1, r, q);
    }
} T;

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    T.build(T.his[0], 1, n);
    for (int i = 1; i <= m; ++i) {
        int pre, op, j, val;
        std::cin >> pre >> op >> j;
        if (op == 1) {
            std::cin >> val;
            T.ins(T.his[i], T.his[pre], 1, n, j, val);
        } else {
            std::cout << T.query(T.his[pre], 1, n, j) << '\n';
            T.his[i] = T.his[pre];
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
