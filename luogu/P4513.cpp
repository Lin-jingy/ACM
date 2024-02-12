#include <bits/stdc++.h>

inline int ls(int p) { return 2 * p; }
inline int rs(int p) { return 2 * p + 1; }

struct node {
    int ans, Lans, Rans, sum;
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::vector<int> ans(n << 4), Lans(n << 4), Rans(n << 4), sum(n << 4);
    auto pushup = [&](int p) -> void {
        sum[p] = sum[ls(p)] + sum[rs(p)];
        Lans[p] = std::max(Lans[ls(p)], sum[ls(p)] + Lans[rs(p)]);
        Rans[p] = std::max(Rans[rs(p)], sum[rs(p)] + Rans[ls(p)]);
        ans[p] = std::max({ans[ls(p)], ans[rs(p)], Rans[ls(p)] + Lans[rs(p)]});
    };
    auto build = [&](auto &&self, int p, int l, int r) -> void {
        if (l == r) {
            ans[p] = Lans[p] = Rans[p] = sum[p] = a[l];
            return;
        }
        int mid = l + r >> 1;
        self(self, ls(p), l, mid);
        self(self, rs(p), mid + 1, r);
        pushup(p);
    };
    auto change = [&](auto &&self, int p, int l, int r, int x, int d) -> void {
        if (l == r) {
            ans[p] = Lans[p] = Rans[p] = sum[p] = d;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) {
            self(self, ls(p), l, mid, x, d);
        } else {
            self(self, rs(p), mid + 1, r, x, d);
        }
        pushup(p);
    };
    auto query = [&](auto &&self, int p, int l, int r, int i, int j) -> node {
        if (i <= l and j >= r) {
            return {ans[p], Lans[p], Rans[p], sum[p]};
        }
        int mid = l + r >> 1;
        if (j <= mid) {
            return self(self, ls(p), l, mid, i, j);
        } else if (i > mid) {
            return self(self, rs(p), mid + 1, r, i, j);
        } else {
            node x = self(self, ls(p), l, mid, i, j);
            node y = self(self, rs(p), mid + 1, r, i, j);
            return {std::max({x.ans, y.ans, x.Rans + y.Lans}), std::max(x.Lans, x.sum + y.Lans),
                    std::max(y.Rans, y.sum + x.Rans), x.sum + y.sum};
        }
    };
    build(build, 1, 1, n);
    while (q--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        if (op == 1) {
            if (x > y) std::swap(x, y);
            std::cout << query(query, 1, 1, n, x, y).ans << '\n';
        } else {
            change(change, 1, 1, n, x, y);
        }
    }
    return 0;
}
