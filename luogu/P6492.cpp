#include <bits/stdc++.h>

inline int ls(int p) { return 2 * p; }
inline int rs(int p) { return 2 * p + 1; }

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> L(n << 2), R(n << 2);
    std::vector<int> ans(n << 2), Lans(n << 2), Rans(n << 2), len(n << 2);
    auto pushup = [&](int p) -> void {
        if (R[ls(p)] != L[rs(p)]) {
            ans[p] = std::max({ans[ls(p)], ans[rs(p)], Rans[ls(p)] + Lans[rs(p)]});
        } else {
            ans[p] = std::max(ans[ls(p)], ans[rs(p)]);
        }
        L[p] = L[ls(p)];
        R[p] = R[rs(p)];
        Lans[p] = Lans[ls(p)];
        Rans[p] = Rans[rs(p)];
        len[p] = len[ls(p)] + len[rs(p)];
        if (R[ls(p)] != L[rs(p)] and Lans[ls(p)] == len[ls(p)]) Lans[p] += Lans[rs(p)];
        if (R[ls(p)] != L[rs(p)] and Rans[rs(p)] == len[rs(p)]) Rans[p] += Rans[ls(p)];
    };
    auto build = [&](auto &&self, int p, int l, int r) -> void {
        if (l == r) {
            L[p] = R[p] = 0;
            ans[p] = Lans[p] = Rans[p] = len[p] = 1;
            return;
        }
        int mid = l + r >> 1;
        self(self, ls(p), l, mid);
        self(self, rs(p), mid + 1, r);
        pushup(p);
    };
    auto change = [&](auto &&self, int p, int l, int r, int x) -> void {
        if (l == r) {
            L[p] ^= 1, R[p] ^= 1;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) {
            self(self, ls(p), l, mid, x);
        } else {
            self(self, rs(p), mid + 1, r, x);
        }
        pushup(p);
    };
    build(build, 1, 1, n);
    while (q--) {
        int x;
        std::cin >> x;
        change(change, 1, 1, n, x);
        std::cout << ans[1] << '\n';
    }
    return 0;
}
