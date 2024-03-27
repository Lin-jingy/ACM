#include <bits/stdc++.h>
#include <corecrt.h>

#if defined (_WIN64)
#define LOG(x) if(!(x)){std::cout<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define LOG(x)
#endif
#define int long long
#define rep(i,b,e) for(int i=b;i<(int)(e);++i)
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
return out;}template<class T,class FUN>void foreach
(std::vector<T>&v,FUN fun){for(int i=0;i<v.size();++i)fun(v[i],i);}
template <class T>void sort(std::vector<T>&v) {std::sort(v.begin(),v.end());}
template <class T,class FUN>void sort(std::vector<T>&v,FUN fun) 
{std::sort(v.begin(),v.end(),fun);}template<class T>void input
(T begin,T end){while(begin!=end)std::cin>>*begin++;}
using Pii = std::pair<int, int>;

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
    int mx = 0, pos;
    auto dfs = [&](auto &&self, int p, int fa, int dis)->void {
        if(dis >= mx) mx = dis, pos = p;
        for(auto i : v[p]) {
            if(i == fa) continue;
            self(self, i, p, dis + 1);
        }
    };
    dfs(dfs, 1, 0, 0);
    mx = 0;
    int begin = pos;
    dfs(dfs, pos, 0, 0);
    vec<int> list;
    auto dfs1 = [&](auto &&self, int p, int fa) ->bool {
        if(p == pos) {
            return true;
        }
        for(auto i: v[p]) {
            if(i == fa) continue;
            list.pb(i);
            if(self(self, i, p)) return true;
            list.pop_back();
        }
        return false;
    };
    list.pb(begin);
    dfs1(dfs1, begin, 0);
    vec<Pii> ans;
    if(list.size() % 2 == 1) {
        int mid = list[list.size() / 2];
        rep(i, 0, list.size() / 2 + 1) {
            ans.push_back({mid, i});
        }
    } else {
        if(list.size() == 2) {
            ans.push_back({1, 0});
            ans.push_back({2, 0});
        }else {
            int midl = list[list.size() / 2 - 1];
            int midr = list[list.size() / 2];
            range(i, 1, list.size() / 2 + 1, 2) {
                ans.push_back({midl, i});
                ans.push_back({midr, i});
            }
        }
        
    }
    std::cout << ans.size() << '\n';
    for(auto [i, j] : ans) std::cout << i << ' ' << j << '\n';
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
