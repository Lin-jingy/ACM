#include<bits/stdc++.h>

#define int long long

struct node {
    int i, j, op, a, b, d, v;
};

int n, m, k;
std::array<int, 7> p;
node a[105];
int ans;

void dfs(int pos) {
    if(pos == n + 1) {
        int sum = 0;
        for(int i = 0; i < m; ++i) {
            node &x = a[i];
            if(x.op == 0) {
                if(x.a * p[x.i] + x.b * p[x.j] <= x.d) sum += x.v;
            }else if(x.op == 1) {
                if(x.a * p[x.i] + x.b * p[x.j] >= x.d) sum += x.v;
            }
        }
        ans = std::max(ans, sum);
        //for(int i = 1; i <= n; ++i) std::cout << p[i] << ' ';
        //std::cout << '\n';
        //std::cout << sum << '\n' << '\n';
        return;
    };
    for(int i = 0; i <= k; ++i) {
        p[pos] = i;
        dfs(pos + 1);
    }
}

void solve() {
    ans = 0;
    std::cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) 
        std::cin >> a[i].i >> a[i].j >> a[i].op >> a[i].a >> a[i].b >> a[i].d >> a[i].v;
    dfs(1);
    std::cout << ans << '\n';
    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}