// #include<bits/stdc++.h>

// const int N = 5e5 + 5;
// std::vector<int>a[N], dep(N);
// int f[N][20];

// void dfs(int pos, int fa){
//     dep[pos] = dep[fa] + 1;
//     f[pos][0] = fa;
//     for(int i = 1; i < 20; ++i) f[pos][i] = f[f[pos][i - 1]][i - 1];
//     for(auto i:a[pos]) if(i != fa) dfs(i, pos);
// }

// int lca(int u, int v){
//     if(dep[u] < dep[v]) std::swap(u, v);
//     for(int i = 19; i >= 0; i--)
//         if(dep[f[u][i]] >= dep[v]) u = f[u][i];
//     if(u == v) return u;
//     for(int i = 19; i >= 0; i--) if(f[u][i] != f[v][i]) 
//         u = f[u][i], v = f[v][i];
//     return f[u][0];
// }

// int main(){
//     int n, m, root;
//     std::cin >> n >> m >> root;
    
//     for(int i(1); i < n; ++i) {
//         int u, v;
//         std::cin >> u >> v;
//         a[u].push_back(v);
//         a[v].push_back(u);
//     }

//     dfs(root, root);

//     while(m--){
//         int u, v;
//         std::cin >> u >> v;
//         std::cout << lca(u, v) << '\n';
//     }


// }


#include<bits/stdc++.h>

const int N = 5e5 + 5;

std::vector<int>a[N], f(N), ans(N);
std::vector<bool>vis(N);
std::vector<std::pair<int, int>> query[N];

void init(int n) {for(int i=1;i<=n;i++)f[i]=i;}
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}

void tarjan(int pos){
    vis[pos] = 1;
    for(auto i:a[pos]) if(!vis[i]) tarjan(i), f[i] = pos;
    for(auto i:query[pos]) if(vis[i.first]) ans[i.second] = find(i.first); 
}

int main(){
    int n, m, root;
    std::cin >> n >> m >> root;
    
    for(int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        query[u].push_back({v, i});
        query[v].push_back({u, i});
    }
    init(n);
    tarjan(root);

    for(int i = 1; i <= m; ++i) std::cout << ans[i] << '\n';
}