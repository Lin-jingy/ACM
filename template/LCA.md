# LCA倍增法

```c++
class LCA {
private:
    std::vector<int> dep;
    std::vector<std::array<int, 20>> f;
    void dfs(int pos, int fa, std::vector<std::vector<int>> &v) {
        dep[pos] = dep[fa] + 1;
        f[pos][0] = fa;
        for (int i = 1; i < 20; ++i) f[pos][i] = f[f[pos][i - 1]][i - 1];
        for (auto i : v[pos])
            if (i != fa) dfs(i, pos, v);
    }
public:
    LCA(int n, std::vector<std::vector<int>> &v) {
        dep.assign(n + 1, {});
        f.assign(n + 1, {});
        dfs(1, 0, v);
    }
    int lca(int u, int v) {
        if (dep[u] < dep[v]) std::swap(u, v);
        for (int i = 19; i >= 0; i--)
            if (dep[f[u][i]] >= dep[v]) u = f[u][i];
        if (u == v) return u;
        for (int i = 19; i >= 0; i--)
            if (f[u][i] != f[v][i])
                u = f[u][i], v = f[v][i];
        return f[u][0];
    }
};
```

# LCA(tarjan)

```c++
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
```