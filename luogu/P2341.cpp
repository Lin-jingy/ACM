#include <bits/stdc++.h>
#include<bits/extc++.h>

#define int long long
#define rep(i,b,e)for(int i=b;i<(e);++i)
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x)emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX
template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}using Pii=std::pair<int,int>;template<class T>using vvec=std::vector<std::vector<T>>;template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;template<class T,size_t S>using arr=std::array<T,S>;class Timer {private:std::chrono::system_clock::time_point begin;public:Timer() { begin = std::chrono::system_clock::now(); }~Timer() {auto end = std::chrono::system_clock::now();auto time = std::chrono::duration<double, std::nano>(end - begin).count();std::clog << "\nThe program takes: " << time / 1e9 << " s\n";}double get() {auto end = std::chrono::system_clock::now();auto time = std::chrono::duration<double, std::nano>(end - begin).count();return time / 1e9;}};
#define vec(type,x,sz,val)std::vector<type>x(sz,val);
#define vvec(type,x,sz1,sz2,val)std::vector<std::vector<type>>x(sz1,std::vector<type>(sz2,val));
#define log(...)PRINT(#__VA_ARGS__" ::",__VA_ARGS__)<<std::endl
template<class...Ts>auto&PRINT(Ts...ts){return((std::clog<<ts<<" "),...);}
#define ensure(x)if(!(x)){std::cerr<<"ensure error:("<<#x<<")->at line:"<<__LINE__<<std::endl;exit(-1);}
template <class _KEY, class _Compare = std::less<_KEY>>
using pbds_set = __gnu_pbds::tree<_KEY, __gnu_pbds::null_type, _Compare,
__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template <class _KEY, class _VALUE, class _Compare = std::less<_KEY>>
using pbds_map = __gnu_pbds::tree<_KEY, _VALUE, _Compare,__gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;

constexpr int N = 1e4 + 5;
void solve() {
    int n, m;
    std::cin >> n >> m;
    vec<vec<int>> v(n + 1);
    vec<int> vis(n + 1);
    for(int i = 1; i <= m; ++i) {
        int a, b;
        std::cin >> a >> b;
        v[b].pb(a);
    }
    int ans = 0;
    int k = n;
    std::bitset<10005> bit;
    bool flag = 0;
    auto dfs = [&](auto &&self, int p) {
        if(bit[p] or flag) return ;
        bit[p] = 1, --k;
        if(k == 0 or vis[p] == 1) {
            ++ans;
            flag = 1;
            return;
        }
        for(auto i:v[p]) self(self, i);
    };
    int last = 0;
    for(int i = 1; i <= n; ++i) {
        k = n;
        flag = 0;
        bit.reset();
        if(vis[i] == -1) continue;
        dfs(dfs, i);
        if(flag) vis[i] = 1;
        else for(auto j:v[i]) vis[j] = -1;
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
