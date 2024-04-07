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
i->first<<","<<i->second<<"}\n";return out;}using Pii=std::pair<int, int>;
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

constexpr int N = 2e5 + 5;
constexpr int mod = 1e9 + 7;
int inv[N], pre[N];

constexpr int qpow(int a, int b) {
    int sum = 1;
    while(b) {
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}
constexpr void init() {
    inv[0] = pre[0] = 1;
    for(int i = 1; i < N; ++i) {
        pre[i] = pre[i - 1] * i % mod;
        inv[i] = qpow(pre[i], mod - 2);
    }
}

constexpr int C(int a, int b) {
    if(a < b) return 0;
    return pre[a] * inv[b] % mod * inv[a - b] % mod;
}

void solve() {
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    vec<int> v1(m1), v2(m2);
    std::cin >> v1 >> v2;
    if(v1.back() != v2.front()) RETURN(std::cout << "0\n");
    int ans = 1, mid = v1.back();
    std::reverse(All(v1));
    for(int i = 1; i <= mid; ++i) {
        if(!v1.empty() and v1.back() == i) v1.pop_back();
        else ans = ans * (i - 1) % mod;
    }
    for(int i = n; i >= mid; --i) {
        if(!v2.empty() and v2.back() == i) v2.pop_back();
        else ans = ans * (n - i) % mod;
    }
    ans = ans * C(n - 1, mid - 1) % mod;
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
