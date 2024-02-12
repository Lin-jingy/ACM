#include<bits/stdc++.h>

struct node {
    int u, v, w;
    friend bool operator< (node a, node b) {
        return a.w < b.w;
    }
};

const int N = 5000;

class DSU {
public:
    int f[N],siz[N];
    void init(int n) {for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
    int qsz(int x){return siz[find(x)];}
}T;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    T.init(n);

    std::vector<node>a;

    while(m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        a.push_back({u, v, w});
    }

    std::sort(a.begin(), a.end());
    int ans = 0;
    for(auto [u, v, w]:a) {
        if(T.same(u, v)) continue;
        else ans += w, T.merge(u, v);
    }

    for(int i = 2; i <= n; ++i) if(T.find(i) != T.find(1)) {
        std::cout << "orz\n";
        return 0;
    }

    std::cout << ans << '\n';

    return 0;
}