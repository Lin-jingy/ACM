#include<bits/stdc++.h>

const int N = 2e5 + 5;

class DSU {
public:
    int f[N],siz[N];
    void init(int n) {for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
    int qsz(int x){return siz[find(x)];}
}T, S;

void solve() {
    int n, q;
    std::cin >> n >> q;
    T.init(n);
    S.init(n);
    while(q--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        if(op == 1) T.merge(x, y);
        else if(op == 2) 
            for(int i = x; i < y; i = S.find(i + 1)) 
                T.merge(i, i + 1), S.f[i] = S.find(i + 1);
        else std::cout << (T.same(x, y) ? "YES\n" : "NO\n");
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}