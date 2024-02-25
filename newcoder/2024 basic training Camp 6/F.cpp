#include <bits/stdc++.h>

// std::vector<int> prime;
// static void get_prime() {  // Euler
//     int n = 1e6;
//     std::bitset<1000005> vis;

//     for(int i = 2; i <= n; ++i) {
//         if(vis[i]) continue;
//         prime.push_back(i);
//         for(int j = i; j <= n; j += i) vis[j] = 1; 
//     }
//     return ;
// }

// static std::vector<int> get_prime_factor(int x) {  // O(sqrt(x))
//     std::vector<int> prime_factor;
//     for(auto i:prime) {
//         if(i > x) break;
//         if(x % i == 0) {
//             prime_factor.push_back(i);
//             while(x % i == 0) x /= i;
//         }
//         if(x != 1) prime_factor.push_back(x);
//     }
//     return prime_factor;
// }
static std::vector<int> get_prime_factor(int x) {  // O(sqrt(x))
    std::vector<int> prime_factor;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            prime_factor.push_back(i);
        }
    }
    if (x != 1) prime_factor.push_back(x);
    return std::move(prime_factor);
}
class DSU {
public:
    std::vector<int> f, siz;
    DSU(int n){f.assign(n+1,{});siz.assign(n+1,{});for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
    int qsz(int x){return siz[find(x)];}
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b, c;
    // std::vector<std::vector<int>> v(n);
    std::unordered_map<int, int> mp;
    DSU T(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
        for(auto j:get_prime_factor(a[i])) {
            if(mp.count(j)) T.merge(i, mp[j]);
            mp[j] = i;
        }
    }
    std::unordered_set<int> L;
    for(int i = 0; i < n; ++i) {
        L.insert(T.find(i));
    }
    if(L.size() >= 2) {
        int fa = *L.begin();
        std::vector<int> A, B;
        for(int i = 0; i < n; ++i) {
            if(T.find(i) == fa) A.push_back(a[i]);
            else B.push_back(a[i]);
        }
        std::cout << A.size() << ' ' << B.size() << '\n';
        for(auto i:A) std::cout << i << ' ';
        std::cout << '\n';
        for(auto i:B) std::cout << i << ' ';
        std::cout << '\n';
    }else {
        std::cout << "-1 -1\n";
    }
    // std::vector<int> vis(n);
    // std::vector<std::vector<int>> list;
    // auto dfs = [&](auto &&self, int p, std::vector<int> &L) {
    //     if(vis[p]) return ;
    //     vis[p] = 1;
    //     L.push_back(p);
    //     for(auto i:v[p]) self(self, i, L);
    // };
    // for(int i = 0; i < n; ++i) {
    //     if(!vis[i]) {
    //         std::vector<int> L;
    //         dfs(dfs, i, L);
    //         list.push_back(L);
    //     }
    // }
    // if(list.size() >= 2) {
    //     std::cout << list.front().size() << ' ' << n - list.front().size() << '\n';
    //     for(auto i:list.front()) std::cout << a[i] << ' ' ;
    //     std::cout << '\n';
    //     for(int i = 1; i < list.size(); ++i) for(auto j:list[i]) std::cout << a[j] << ' ';
    //     std::cout << '\n';
    // }else {
    //     std::cout << "-1 -1\n";
    // }
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // get_prime();
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}