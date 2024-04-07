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

void solve() {
    int n;
    std::cin >> n;
    vec<vec<int>> v(n + 1);
    rep(i, 1, n) {
        int a, b;
        std::cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    vec<int> c(n + 1), up(n + 1), down(n + 1), sumdown(n + 1);
    int sum = 0;
    rep(i, 1, n + 1) std::cin >> c[i], sum += c[i];
    int ans = LONG_LONG_MAX;
    auto dfs = [&](auto &&self, int p, int fa) ->void{
        for(auto i:v[p]) {
            if(i == fa) continue;
            self(self, i, p);
            down[p] += down[i] + sumdown[i];
            sumdown[p] += sumdown[i];
        }
        sumdown[p] += c[p];
    };
    dfs(dfs, 1, 0);
    auto dfs1 = [&](auto &&self, int p, int fa) ->void {
        ans = std::min(ans, up[p] + down[p]);
        int add = 0;
        for(auto i:v[p]) {
            if(i == fa) continue;
            add += down[i];
        }
        for(auto i:v[p]) {
            if(i == fa) continue;
            up[i] = up[p] + sum - sumdown[i] + add - down[i] + sum - sumdown[i] - (sum - sumdown[p]) - c[p];
            self(self, i, p);
        }
        
    };
    dfs1(dfs1, 1, 0);
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}
