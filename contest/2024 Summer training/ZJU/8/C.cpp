#include <bits/stdc++.h>

constexpr int N = 5e5 + 10;
std::vector<std::vector<int>> rv(N);
bool vis[N];
int du[N];
bool s[N];
int n, m, q, k;

void dfs(int p) {
    assert(p >= 1 and p <= n);
    if(vis[p]) return ;
    if(!s[p]) {
        if(du[p] > k) {
            s[p] = 1;
            for(auto i:rv[p]) du[i]++;
        } else return ;
    }
    if(s[p]) vis[p] = 1;
    for(auto i:rv[p]) dfs(i);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> m >> q >> k;
    std::vector<int> end(q);
    for(int i = 0; i < q; ++i) std::cin >> end[i], s[end[i]] = 1;

    
    for(int i = 1; i <= m; ++i) {
        int a, b;
        std::cin >> a >> b;
        rv[b].push_back(a);
    }

    
    for(auto i:end) {
        for(auto j:rv[i]) ++du[j];
    }

    for(auto i:end) 
        dfs(i);

    for(int i = 1; i <= n; ++i) {
        if(s[i]) std::cout << "S";
        else std::cout << "B";
    }


    return 0;
}