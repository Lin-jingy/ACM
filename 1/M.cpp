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
    int n, m;
    std::cin >> n >> m;
    vec<vec<int>> v(n + 1, vec<int>(m + 1));
    rep(i, 1, n + 1) {
        std::string s;
        std::cin >> s;
        rep(j, 0, m) {
            if(s[j] == '#') v[i][j + 1] = 0;
            else v[i][j + 1] = 1;
        }
    }
    vec<vec<int>> pre(n + 1, vec<int>(m + 1)), vis(n + 1, vec<int>(m + 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+v[i][j];
        }
    }
    auto get = [&](int x1,int y1,int x2,int y2)->int{
        return pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];
    };
    auto is = [&](int i, int j) ->bool {
        if(get(i, j, i + 3, j + 3) == 12 and v[i][j] == 0 and v[i + 3][j] == 0 and v[i][j + 3] == 0 and v[i + 3][j + 3] == 0) return true;
        return false;
    };
    int ans1 = 0, ans2 = 0;
    auto check = [&](int i, int j) -> void {
        if(i + 16 <= n and j + 9 <= m and get(i, j, i + 16, j + 9) == 24 and is(i + 3, j + 3) and is(i + 10, j + 3)) {
            rep(I, i, i + 17) rep(J, j, j + 10) vis[I][J] = 1;
            ++ans1;
        }
        if(i + 9 <= n and j + 16 <= m and get(i, j, i + 9, j + 16) == 24 and is(i + 3, j + 3) and is(i + 3, j + 10)) {
            rep(I, i, i + 10) rep(J, j, j + 17) vis[I][J] = 1;
            ++ans1;
        }
    };
    auto check1 = [&](int i, int j) ->void {
        if(i + 9 <= n and j + 9 <= m and get(i, j, i + 9, j + 9) == 12 and is(i + 3, j + 3)) {
            rep(I, i, i + 10) rep(J, j, j + 10) if(vis[I][J]) return;
            rep(I, i, i + 10) rep(J, j, j + 10) vis[I][J] = 1;
            ++ans2;
        }
    };
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            check(i, j);
        }
    }
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            check1(i, j);
        }
    }
    std::cout << ans1 << ' ' << ans2 << '\n';
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}
