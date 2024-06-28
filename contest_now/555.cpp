#include <bits/stdc++.h>
constexpr int N = 3e5 + 5;
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
using Pii = std::pair<int, int>;
int f[N << 3], tag[N << 3];
std::string s;
void pushDown(int p, int l, int r) {
    int mid = (l + r) >> 1;
    tag[p] %= 2;
    if(!tag[p]) return ;
    tag[p] = 0;
    f[ls(p)] = (mid - l + 1) - f[ls(p)];
    f[rs(p)] = (r - mid) - f[rs(p)];
    tag[ls(p)]++;
    tag[rs(p)]++;
}
void pushUp(int p, int l, int r) {
    int mid = (l + r) >> 1;
    if((mid - l + 1) % 2 == 1) {
        f[p] = f[ls(p)] + (r - mid) - f[rs(p)];
    } else {
        f[p] = f[ls(p)] + f[rs(p)];
    }
}
void build(int p, int l, int r) {
    if(l == r) {
        if(s[l] == '1') f[p] = 1;
        else f[p] = 0;
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
        f[p] = (r - l + 1) - f[p];
        return ;
    }
    int mid = (l + r) >> 1;
    if(i <= mid) update(ls(p), l, mid, i, j);
    if(j > mid) update(rs(p), mid + 1, r, i, j);
    pushUp(p, l, r);
}
int query(int p, int l, int r, int i, int j) {
    if(i == l and j == r) return f[p];
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    if(i <= mid and j > mid) {
        int L = query(ls(p), l, mid, i, mid);
        int R = query(rs(p), mid + 1, r, mid + 1, j);
        if((mid - i + 1) % 2 == 1) return L + (j - mid) - R;
        else return L + R;
    } else if(i <= mid) return query(ls(p), l, mid, i, j);
    else if(j > mid) return query(rs(p), mid + 1, r, i, j);
    assert(false);
    return 0;
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
            int k = query(1, 1, n, l, r);
            std::cout << std::min(k, (r - l + 1) - k) << '\n';
        }
    }
    return 0;
}