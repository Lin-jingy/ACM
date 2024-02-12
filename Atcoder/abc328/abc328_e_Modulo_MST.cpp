#include<bits/stdc++.h>

#define int long long

struct node {
    int u, v, w;
    // friend bool operator< (const node a, const node b) {
    //     return a.u < b.u;
    // } 
};

std::vector<node> a;
bool p[10];
int n, m, k, ans = LONG_LONG_MAX;

void dfs(int num, int sum) {
    if(num == n - 1) {
        ans = std::min(ans, sum % k);
        return ;
    }
    for(int i = 0; i < a.size(); ++i) {
        if(p[a[i].u] and !p[a[i].v]) {
            p[a[i].v] = 1;
            dfs(num + 1, sum + a[i].w);
            p[a[i].v] = 0;
        }
        if(!p[a[i].u] and p[a[i].v]) {
            p[a[i].u] = 1;
            dfs(num + 1, sum + a[i].w);
            p[a[i].u] = 0;
        }
    }
}

void solve() {
    std::cin >> n >> m >> k;
    while(m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        a.push_back({u, v, w});
    }
    //std::sort(a.begin(), a.end());
    p[1] = 1;
    dfs(0, 0);
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