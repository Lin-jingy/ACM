// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

const int N = 105;
class DSU {
public:
    int f[N],siz[N];
    void init(int n) {for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
    int qsz(int x){return siz[find(x)];}
}T;

class node{
public:
    int val;
    int x, y;
    friend bool operator< (const node &a, const node &b){
        return a.val > b.val;
    }
};

void solve(){
    int c, n, m;
    std::cin >> c >> n >> m;
    T.init(m);
    std::priority_queue<node>q;
    for(int i(1); i <= n; ++i) {
        int u, v, k;
        std::cin >> u >> v >> k;
        q.push({k, u, v});
    }
    int ans(0);
    while(!q.empty()){
        auto it = q.top();
        q.pop();
        if(!T.same(it.x, it.y)){
            ans += it.val;
            T.merge(it.x, it.y);
        }
    }
    std::unordered_set<int>s;
    for(int i(1); i <= m; ++i) s.insert(T.find(i));
    if(s.size() == 1 and ans <= c) yes;
    else no;

    
    
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    //std::cin >> _;
    while (_--)
        solve();
    return 0;
}
