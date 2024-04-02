#include <bits/stdc++.h>
#include <system_error>

#if defined (_WIN64)
#define log(x...) do{std::cout<<#x<<" -> ";_log(x);}while(0)
void _log(){std::cout<<std::endl;}
template<class T,class ...Ts>
void _log(T arg,Ts ...args){std::cout<<arg<<' ';_log(args...);}
#define sure(x) if(!(x)){std::cerr<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define log(x...)
#define sure(x)
#endif
#define int long long
#define rep(i,b,e) for(int i=b;(b<e?i<e:i>e);i+=(b<e?1:-1))
#define range(i,b,e,step) for(int i=b;(b<e?i<e:i>e);i+=(b<e?step:-step))
#define RETURN(x) do{return x,void();}while(0);
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX;
template <class T>using vec=std::vector<T>;
template<class K,class V> using umap=std::unordered_map<K,V>;
template<class T>std::istream& operator>>(std::istream&in,std::vector<T>&v) 
{for(auto &i:v)in>>i;return in;}template<class T>std::ostream& 
operator<<(std::ostream&out,const std::vector<T>&v) {
for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];
return out;}template <class T>void sort(std::vector<T>&v) 
{std::sort(v.begin(),v.end());}template <class T,class FUN>void 
sort(std::vector<T>&v,FUN fun) {std::sort(v.begin(),v.end(),fun);}
template<class T>void input(T begin,T end){while(begin!=end)std::cin>>*begin++;}
using Pii = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    vec<int> du(n + 1);
    rep(i, 1, n) {
        int a, b;
        std::cin >> a >> b;
        du[a]++;
        du[b]++;
    }
    int ans = 0;
    rep(i, 1, n + 1) {
        if(du[i] == 1) ans++;
    }
    std::cout << (ans + 1) / 2 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
