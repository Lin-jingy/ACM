#include <bits/stdc++.h>

#if defined (_WIN64)
#pragma clang diagnostic ignored "-Wunused-value"
// #pragma clang diagnostic ignored "-Wshift-op-parentheses"
#endif
#define int long long
template <class T>using vec=std::vector<T>;
template<class K,class V> using umap=std::unordered_map<K,V>;
template<class T>std::istream& operator>>(std::istream& in,std::vector<T>& v) 
{for(auto &i: v)in>>i;return in;}template<class T>std::ostream& 
operator<<(std::ostream& out, const std::vector<T>& v) {
for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];
return out;}template<class T>void foreach(std::vector<T>&v,
std::function<void(T&,int)>fun){for(int i=0;i<v.size();++i)fun(v[i],i);}
template<class T,class FUN>void foreach(std::vector<T>&v,FUN fun)
{for(int i=0;i<v.size();++i)fun(v[i],i);}
using Pii = std::pair<int, int>;using i128 = __int128;
#define RETURN(x) do{return x,void();}while(0);
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf = INT_MAX
#define INF = LONG_LONG_MAX;

class DSU {
private:
    std::vector<int> f;
public:
    DSU(int n):f(n+1){for(int i=1;i<=n;i++)f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))f[find(x)]=find(y);}
};

void solve() {
    int n;
    std::cin >> n;
    vec<int> X(n), Y(n), OP(n);
    for(int i = 0; i < n; ++i) std::cin >> X[i] >> Y[i] >> OP[i];
    std::map<int, int> mp;
    int f = 0;
    for(auto i:X) if(!mp.count(i)) mp[i] = ++f;
    for(auto i:Y) if(!mp.count(i)) mp[i] = ++f;
    int N = mp.size();
    DSU T(N + 5);
    for(int i = 0; i < n; ++i) {
        int x = mp[X[i]], y = mp[Y[i]], op = OP[i];
        if(op == 1) T.merge(x, y);
    }
    for(int i = 0; i < n; ++i) {
        int x = mp[X[i]], y = mp[Y[i]], op = OP[i];
        if(op == 0 and T.same(x, y)) RETURN(std::cout << "NO\n");
    }
    std::cout << "YES\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
