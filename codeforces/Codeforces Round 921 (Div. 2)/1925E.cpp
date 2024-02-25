#include <bits/stdc++.h>

#define int long long
int ls(int p) { return p << 1; }
int rs(int p) { return p << 1 | 1; }

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> pos(m), val(m);
    for(int &i:pos) std::cin >> i;
    for(int &i:val) std::cin >> i;
    std::map<int, int> S;
    for(int i = 0; i < m; ++i) S[pos[i]] = val[i];
    std::vector<int> f(n << 2);
    std::vector<int> B(n << 2), D(n << 2);
    auto pushUp = [&](int p) {
        f[p] = f[ls(p)] + f[rs(p)];
    };
    auto pushDown = [&](int p, int l, int r) {
        if(B[p]) {
            int mid = (l + r) >> 1;
            B[ls(p)] = B[p];
            B[rs(p)] = B[p] + (mid - l + 1) * D[p];
            D[ls(p)] = D[rs(p)] = D[p];
            B[p] = 0, D[p] = 0;
            f[ls(p)] = (mid - l + 1) * (B[ls(p)] + B[ls(p)] + (mid - l) * D[ls(p)]) / 2;
            f[rs(p)] = (r - mid) * (B[rs(p)] + B[rs(p)] + (r - mid - 1) * D[rs(p)]) / 2;
        }
    };
    auto build = [&](auto &&self, int p, int l, int r) {
        if(l == r) {
            if(S.count(l)) {
                f[p] = 0;
            } else {
                auto L = --S.lower_bound(l);
                auto R = S.lower_bound(l);
                f[p] = L->second * (R->first - l);
            }
            return ;
        }
        int mid = (l + r) >> 1;
        self(self, ls(p), l, mid);
        self(self, rs(p), mid + 1, r);
        pushUp(p);
    };
    auto update = [&](auto &&self, int p, int l, int r, int i, int j, int val1, int val2) {
        if(i > j) return ;
        if(i <= l && r <= j) {
            B[p] = val1;
            D[p] = val2;
            f[p] = (r - l + 1) * (val1 + val1 + (r - l) * val2) / 2;
            return ;
        }
        pushDown(p, l, r);
        int mid = (l + r) >> 1;
        if(j <= mid) self(self, ls(p), l, mid, i, j, val1, val2);
        else if(i > mid) self(self, rs(p), mid + 1, r, i, j, val1, val2);
        else {
            self(self, ls(p), l, mid, i, mid, val1, val2);
            self(self, rs(p), mid + 1, r, mid + 1, j, val1 + (mid - i + 1) * val2, val2);
        }
        pushUp(p);
    };
    auto query = [&](auto &&self, int p, int l, int r, int i, int j) -> int {
        if(i <= l && r <= j) return f[p];
        pushDown(p, l, r);
        int mid = (l + r) >> 1;
        int sum = 0;
        if(i <= mid) sum += self(self, ls(p), l, mid, i, j);
        if(j > mid) sum += self(self, rs(p), mid + 1, r, i, j);
        return sum;
    };
    build(build, 1, 1, n);
    while(q--) {
        int op;
        std::cin >> op;
        if(op == 1) {
            int x, v;
            std::cin >> x >> v;
            auto L = *(--S.lower_bound(x));
            auto R = *S.lower_bound(x);
            S[x] = v;
            update(update, 1, 1, n, L.first + 1, x - 1, (x - L.first - 1) * L.second, -L.second);
            update(update, 1, 1, n, x + 1, R.first - 1, (R.first - x - 1) * v, -v);
            update(update, 1, 1, n, x, x, 0, 0);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << query(query, 1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}