#include <bits/stdc++.h>

constexpr int N = 3e5 + 5;
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
using Pii = std::pair<int, int>;
int f0[N << 2], f1[N << 2], tag[N << 2];
std::string s;
void pushDown(int p, int l, int r) {
    int mid = (l + r) >> 1;
    tag[p] %= 2;
    if(tag[p]) {
        tag[p] = 0;
        f0[ls(p)] = (mid - l + 1) - f0[ls(p)];
        f1[ls(p)] = (mid - l + 1) - f1[ls(p)];
        f0[rs(p)] = (r - mid) - f0[rs(p)];
        f1[rs(p)] = (r - mid) - f1[rs(p)];
        tag[ls(p)]++;
        tag[rs(p)]++;
    }
}
void pushUp(int p, int l, int r) {
    int mid = (l + r) >> 1;
    if((mid - l + 1) % 2 == 1) {
        f0[p] = f0[ls(p)] + f1[rs(p)];
        f1[p] = f1[ls(p)] + f0[rs(p)];
    } else {
        f0[p] = f0[ls(p)] + f0[rs(p)];
        f1[p] = f1[ls(p)] + f1[rs(p)];
    }
}
void build(int p, int l, int r) {
    if(l == r) {
        if(s[l] == '1') {
            f0[p] = 1;
            f1[p] = 0;
        }else {
            f0[p] = 0;
            f1[p] = 1;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushUp(p, l, r);
}
void update(int p, int l, int r, int i, int j) {
    pushDown(p, l, r);
    if(i <= l and j >= r) {
        tag[p]++;
        f0[p] = (r - l + 1) - f0[p];
        f1[p] = (r - l + 1) - f1[p];
        return ;
    }
    int mid = (l + r) >> 1;
    if(i <= mid) update(ls(p), l, mid, i, j);
    if(j > mid) update(rs(p), mid + 1, r, i, j);
    pushUp(p, l, r);
}
Pii query(int p, int l, int r, int i, int j) {
    if(i <= l and j >= r) return {f0[p], f1[p]};
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    if(i <= mid and j > mid) {
        Pii L = query(ls(p), l, mid, i, j);
        Pii R = query(rs(p), mid + 1, r, i, j);
        int F0, F1;
        if((mid - i + 1) % 2 == 1) {
            F0 = L.first + R.second;
            F1 = L.second + R.first;
        } else {
            F0 = L.first + R.first;
            F1 = L.second + R.second;
        }
        return {F0, F1};
    } else if(i <= mid) return query(ls(p), l, mid, i, j);
    else if(j > mid) return query(rs(p), mid + 1, r, i, j);
    assert(false);
    return {};
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, q;
    std::cin >> n >> q;
    std::cin >> s;
    s = ' ' + s;
    build(1, 1, n);

    for(int i = 1; i <= q; ++i) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if(op == 1) {
            update(1, 1, n, l, r);
        } else {
            Pii k = query(1, 1, n, l, r);
            assert(k.first + k.second == (r - l + 1));
            std::cout << std::min(k.first, k.second) << std::endl;
        }
    }

    return 0;
}