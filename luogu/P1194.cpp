#include <bits/stdc++.h>

struct node {
    int v, a, b;
    friend bool operator< (node a, node b) {
        return a.v > b.v;
    }
};

const int N = 505;

class DSU {
private:
    int f[N],siz[N];
public:
    void init(int n) {for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
    int qsz(int x){return siz[find(x)];}
}T;

void solve() {
    int a, b;
    std::cin >> a >> b;
    std::priority_queue<node> q;
    for(int i = 0; i < b; ++i) {
        for(int j = 0; j < b; ++j) {
            int v;
            std::cin >> v;
            if(v != 0 and v <= a) q.push({v, i + 1, j + 1});
        }
    }
    long long ans = 0;
    T.init(b);
    while(!q.empty()) {
        auto x = q.top();
        q.pop();
        if(T.same(x.a, x.b)) continue;
        ans += x.v;
        T.merge(x.a, x.b);
    }
    std::set<int> s;
    for(int i = 1; i <= b; ++i) s.insert(T.find(i));
    ans += s.size() * a;
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}
