#include <bits/stdc++.h>

#define int long long
#define rep(i,b,e) for(int i=b;i<e;++i)
#define RETURN(x) do{return x,void();}while(0)
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX;
template <class T>using vec=std::vector<T>;using str=std::string;
template<class K,class V> using umap=std::unordered_map<K,V>;
template<class T>std::istream& operator>>(std::istream&in,std::vector<T>&v) 
{for(auto &i:v)in>>i;return in;}template<class T>std::ostream& 
operator<<(std::ostream&out,const std::vector<T>&v) {
for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];
return out;}template<class T>std::ostream&operator<<(std::ostream&out,
const std::set<T>&s) {out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();
i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,
class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp) 
{out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<
i->first<<","<<i->second<<"}\n";return out;}template <class T>void sort(T&v) 
{std::sort(v.begin(),v.end());}template <class T,class FUN>void 
sort(std::vector<T>&v,FUN fun) {std::sort(v.begin(),v.end(),fun);}
using Pii = std::pair<int, int>;
#if defined (_WIN64)
#define log(x...) do{std::clog<<#x<<" -> ";_log(x);}while(0)
void _log(){std::clog<<std::endl<<std::endl;}
template<class T,class ...Ts>
void _log(T arg,Ts ...args){std::clog<<arg<<' ';_log(args...);}
#define sure(x) if(!(x)){std::cerr<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define log(x...)
#define sure(x)
#endif

void solve() {
    int n, _x;
    std::cin >> n >> _x;
    std::bitset<32> x(_x + 1);
    vec<std::bitset<32>> a(n);
    int ans = -1;
    rep(i, 0, n) {
        int x;
        std::cin >> x;
        a[i] = x;
    }
    // log(a);
    for(int i = 30; i >= 0; --i) {
        vec<std::bitset<32>> b;
        int f = 0;
        for(auto j:a) {
            if(!f) b.pb(j);
            else b.back() ^= j;
            if(j[i] == 1) f ^= 1;
        }
        if(x[i] == 1 and !f) ans = std::max(ans, (int)b.size());
        else if(x[i] == 0 and f) RETURN(std::cout << ans << '\n');
        else if(x[i] == 0) a = b;
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
