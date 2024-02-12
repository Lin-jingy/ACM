#include<bits/stdc++.h>
#include<unordered_map>

#define int long long 

// const int N = 100;

// class DSU {
// private:
//     int f[N],siz[N];
// public:
//     void init(int n) {for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;}
//     int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
//     bool same(int x,int y){return find(x)==find(y);}
//     void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
//     int qsz(int x){return siz[find(x)];}
// }T;

// void solve(){
//     int n;
//     std::cin >> n;
//     T.init(99);
//     int a, b, l, r;
//     for(int i = 1; i <= n; ++i){
//         std::cin >> a >> b >> l >> r;
//         for(int i = a; i <= r; ++i) if(T.find(i) <= r)T.merge(i, r);
//     }
    
//     int q;
//     std::cin >> q;
//     while(q--){
//         int x;
//         std::cin >> x;
//         std::cout << T.find(x) << ' ';
//     }
//     std::cout << '\n';


// }

struct node{int l, r;};

void solve(){
    int n;
    std::cin >> n;
    std::map<int, int>mp;
    std::vector<node>a(n);
    for(int i = 0, x; i < n; ++i) std::cin >> a[i].l >> x >> x >> a[i].r;

    std::sort(a.begin(), a.end(), [&](node aa, node bb){
        return aa.r > bb.r;
    });
    
    for(int i = 0; i < n; ++i){
        int ll = a[i].l, rr = a[i].r;
        while(i != n - 1 and a[i + 1].r >= ll){
            ++i;
            ll = std::min(ll, a[i].l);
        }
        mp[ll] = rr;
    }

    int q;
    std::cin >> q;
    while(q--){
        int x;
        std::cin >> x;
        auto it = mp.upper_bound(x);
        if(it == mp.begin() or (--it)->second < x) std::cout << x << ' ';
        else std::cout << it->second << ' '; 
    }
    std::cout << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}