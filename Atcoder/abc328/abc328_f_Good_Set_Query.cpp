#include<bits/stdc++.h>

#define int long long
const int N = 2e5 + 5;

class DSU {
private:
    int f[N], w[N];
public:
    void init(int n) {for(int i=1;i<=n;i++)f[i]=i,w[i]=0;}
    int find(int x){
        if(f[x] != x) {
            int p = f[x];
            f[x] = find(f[x]);
            w[x] += w[p];
        }
        return f[x];
    }
    bool add(int x, int y, int d){
        if(find(x) == find(y) and w[x] - w[y] != d) return false;
        else return true;
    }
    void merge(int x, int y, int d) {
        int a = find(x), b = find(y);
        f[a] = b;
        w[a] = -w[x] + d + w[y];
    }
}T;

void solve() {
    int n, m;
    std::cin >> n >> m;
    T.init(n);
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        if(T.add(u, v, w)) {
            T.merge(u, v, w);
            std::cout << i << ' ';
        }
    } 
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