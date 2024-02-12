#include <iostream>
#include <vector>

int ls(int p) { return p * 2; }
int rs(int p) { return p * 2 + 1; }

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), mn(n << 2), mx(n << 2);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    auto pushup = [&](int p) -> void {
        if (a[mn[ls(p)]] < a[mn[rs(p)]])
            mn[p] = mn[ls(p)];
        else
            mn[p] = mn[rs(p)];
        if (a[mx[ls(p)]] < a[mx[rs(p)]])
            mx[p] = mx[rs(p)];
        else
            mx[p] = mx[ls(p)];
    };
    auto build = [&](auto &&self, int p, int l, int r) -> void {
        if (l == r) {
            mn[p] = mx[p] = l;
            return;
        }
        int mid = l + r >> 1;
        self(self, ls(p), l, mid);
        self(self, rs(p), mid + 1, r);
        pushup(p);
    };
    auto query = [&](auto &&self, int p, int l, int r, int i, int j) -> std::pair<int, int> {
        if (i <= l && j >= r) {
            return {mn[p], mx[p]};
        }
        int mid = l + r >> 1;
        if (j <= mid)
            return self(self, ls(p), l, mid, i, j);
        else if (i > mid)
            return self(self, rs(p), mid + 1, r, i, j);
        else {
            std::pair<int, int> x = self(self, ls(p), l, mid, i, j);
            std::pair<int, int> y = self(self, rs(p), mid + 1, r, i, j);
            int xx, yy;
            if (a[x.first] < a[y.first])
                xx = x.first;
            else
                xx = y.first;
            if (a[x.second] < a[y.second])
                yy = y.second;
            else
                yy = x.second;
            return {xx, yy};
        }
    };
    int q;
    std::cin >> q;
    build(build, 1, 1, n);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::pair<int, int> x = query(query, 1, 1, n, l, r);
        if (a[x.first] != a[x.second]) {
            std::cout << x.first << ' ' << x.second << '\n';
        } else {
            std::cout << "-1 -1\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
