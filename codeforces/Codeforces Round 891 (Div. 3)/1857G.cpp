#include<bits/stdc++.h>

const int mod = 998244353;
const int N = 2e5 + 5;

struct node{
    int u,v;
    long long w;
    friend bool operator< (node a, node b) {
        return a.w < b.w;
    }

}F[N];

class DSU {
public:
    long long f[N],siz[N];
    void init(int n) {for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
    int qsz(int x){return siz[find(x)];}
}T;

long long qpow(long long a, long long b){
    long long sum = 1;
    while(b) {
        if(b & 1) sum = sum * a % mod; 
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

void solve() {
    long long n, s;
    std::cin >> n >> s;
    T.init(n);
    for(int i = 1; i < n; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        F[i] = {u, v, w};
    }
    std::sort(F + 1, F + n);
    long long ans = 1;
    for(int i = 1; i < n; i++){
        int u = T.find(F[i].u), v = T.find(F[i].v);
        long long sume = T.siz[u] * T.siz[v] - 1;//可以加入的边数
        long long sum = qpow(s - F[i].w + 1, sume);//二项式定理
        ans = ans * sum % mod;
        T.merge(u, v);
    }
    std::cout << ans << '\n';

} 
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}