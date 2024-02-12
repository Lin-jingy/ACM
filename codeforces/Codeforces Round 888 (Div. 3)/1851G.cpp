// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "YES\n"
#define no std::cout << "NO\n"

const int N = 10;
std::vector<int>v[N];

class DSU {
private:
    int f[N],siz[N];
public:
    void init(int n) {for(int i=0;i<=n;i++)siz[i]=1,f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
    int qsz(int x){return siz[find(x)];}
}T;

class node{
public:
    int a, b, k;
    int sum;
    friend bool operator< (node a, node b){
        return a.sum < b.sum;
    }
};

void solve(){
    int n, m;
    std::cin >> n >> m;
    std::vector<PII>a(n);
    for(size_t i(0); i < n; ++i) std::cin >> a[i].first, a[i].second = i, v[i].clear();
    while(m--){
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int q;
    std::cin >> q;
    std::vector<node>qs;
    std::vector<int>sss(q);
    for(size_t i(0); i < q; ++i)sss[i] = i;
    T.init(n);
    for(size_t i(0); i < q; ++i){
        node x;
        std::cin >> x.a >> x.b >> x.k;
        --x.a, --x.b;
        x.sum = a[x.a].first + x.k;
        qs.push_back(x);
    }
    std::sort(ALL(sss), [&](int a, int b){
        return qs[a].sum < qs[b].sum;
    });
    std::sort(ALL(qs));
    std::vector<int>ans(q);
    int flag(0);
    for(auto i:qs){
        while(!a.empty() and a.back().first <= i.sum){
            auto x = a.back();
            a.pop_back();
            for(auto j:v[x.second]) if(a[j].first <= i.sum)T.merge(j, x.second);
        }
        if(T.same(i.a, i.b))ans[sss[flag++]] = 1;
        else ++flag;
    }
    for(auto i:ans){
        if(i == 1) yes;
        else no;
    }
    std::cout << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    
    return 0;
}
