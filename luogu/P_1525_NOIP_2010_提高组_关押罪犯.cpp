#include<bits/stdc++.h>

#define int long long

struct node {
    int a, b, v;
    friend bool operator< (node a, node b) {
        return a.v > b.v;
    }
};

const int N = 4e4 + 5;
class DSU {
private:
    int *f, *siz;
public:
    DSU(int n) {
        f=(int*)malloc((n + 5)*sizeof(int));
        siz=(int*)malloc((n + 5)*sizeof(int));
        for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;
    }
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
    int qsz(int x){return siz[find(x)];}
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<node> a(m);
    for(int i = 0; i < m; ++i) std::cin >> a[i].a >> a[i].b >> a[i].v;
    std::sort(a.begin(), a.end());
    int mx = 0;
    DSU *T = new DSU(2 * n);
    for(auto [x, y, v]:a) {
        if(T->same(x, y)) {
            mx = std::max(mx, v);
            break;
        }
        else {
            T->merge(x, y + n);
            T->merge(x + n, y);
        }
    }
    std::cout << mx << '\n';
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