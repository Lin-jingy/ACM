#include <bits/stdc++.h>

#define int long long
const int mod = 998244353;

const int N = 3e5 + 5;
int a[N];

class SegmentTree{
private:
    inline int ls(int x){return x << 1;}
    inline int rs(int x){return x << 1|1;}
    int f[N << 2];//?维护的区间值
    inline void push_up(int p){//?自下而上传递区间值
        if(a[f[ls(p)]] < a[f[rs(p)]])
            f[p] = f[ls(p)];
        else
            f[p] = f[rs(p)];
    }

public:
    void build(int p, int l, int r){//?建树
        if(l == r){
            f[p] = l;
            return;
        }
        int mid = l + r >> 1;
        build(ls(p), l, mid);
        build(rs(p), mid + 1, r);
        push_up(p);//更新值
    }
    int query(int p, int l, int r, int i, int j){//?查询[i,j]区间值
        if(l >= i and r <= j) return f[p];
        int mid = l + r >> 1;
        int x = i, y = j;
        if(i <= mid) x = query(ls(p), l, mid, i, j);
        if(j > mid) y = query(rs(p), mid + 1, r, i, j);
        if(a[x] < a[y]) return x;
        else return y;
    }
} T;

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n;++i) std::cin >> a[i];
    T.build(1, 1, n);
    auto dfs = [&](auto dfs, int l, int r) -> int {
        if(l > r) return 1;
        int p = T.query(1, 1, n, l, r);
        int ans = 0;
        ans = dfs(dfs, l, p - 1) * dfs(dfs, p + 1, r) % mod;
        if(l != 1) ans = (ans + dfs(dfs, p + 1, r)) % mod;
        if(r != n) ans = (ans + dfs(dfs, l, p - 1)) % mod;
        if(l != 1 and r != n) ans--;
        return (ans + mod) % mod;
    };
    std::cout << dfs(dfs, 1, n) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
