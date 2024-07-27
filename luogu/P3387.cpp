#include <bits/stdc++.h>

#if __GNUC__
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
template<class _KEY,class _Compare=std::less<_KEY>>using pbds_set=__gnu_pbds::tree<_KEY,__gnu_pbds::null_type,_Compare,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;template<class _KEY,class _VALUE,class _Compare=std::less<_KEY>>using pbds_map=__gnu_pbds::tree<_KEY,_VALUE,_Compare,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;template <class T, class Comp = std::less<T>>using pbds_heap = __gnu_pbds::priority_queue<T, Comp, __gnu_pbds::pairing_heap_tag>;
#endif
#if __SIZEOF_POINTER__==8&&__GNUC__&&__cplusplus>=202002L
using i128=__int128;std::istream&operator>>(std::istream&in,__int128&value){std::string s;in>>s;value=0;bool op=0;std::ranges::reverse(s);if(s.back()=='-'){op=1;s.pop_back();}while(!s.empty())value=value*10+s.back()-'0',s.pop_back();if(op)value=-value;return in;}std::ostream&operator<<(std::ostream&out,const __int128&value){__int128 x=(value<0?-value:value);if(value<0)out<<'-';std::string s;while(x){s+=(char)(x%10+'0');x/=10;}std::ranges::reverse(s);out<<s;return out;}template<class...Args>void print(const std::string_view&fmtStr,Args&&...args){std::cout<<std::vformat(fmtStr,std::make_format_args(args...));}
#endif
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x...)emplace_back(x)
#define fmt(x...)std::format(x)
#define logs(x...)Print_log(#x" ::",x)<<std::endl
#define ensure(x)if(!(x)){std::cerr<<"ensure error:("<<#x<<")->at line:"<<__LINE__<<std::endl;exit(-1);}
constexpr int inf=INT_MAX;constexpr long long INF=LONG_LONG_MAX;template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;using Pii=std::pair<int,int>;template<class T>using vvec=std::vector<std::vector<T>>;template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;template<class T,size_t S>using arr=std::array<T,S>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};template<bool print=false>class Timer{private:std::chrono::system_clock::time_point begin;public:Timer(){begin=std::chrono::system_clock::now();}~Timer(){if constexpr(print){auto end=std::chrono::system_clock::now();auto time=std::chrono::duration<double,std::nano>(end-begin).count();std::clog<<"\nThe program takes: "<<time/1e9<<" s\n";}}double get(){auto end=std::chrono::system_clock::now();auto time=std::chrono::duration<double,std::nano>(end-begin).count();return time/1e9;}};template<class...Ts>auto&Print_log(Ts...ts){return((std::clog<<ts<<" "),...);}
void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

static std::vector<std::vector<int>> 
Tarjan(std::vector<std::vector<int>> &v) {
    int cnt = 0;
    std::vector<std::vector<int>> component;
    std::vector<int> dfn(v.size()), low(v.size());
    std::vector<bool> instack(v.size());
    std::stack<int> s;
    auto tarjan = [&](auto self, int p) ->void {
        dfn[p] = low[p] = ++cnt;
        s.push(p);
        instack[p] = true;
        for (auto i:v[p]) {
            if (!dfn[i]) {
                self(self, i);
                low[p] = std::min(low[p], low[i]);
            } else if (instack[i]) {
                low[p] = std::min(low[p], dfn[i]);
            }
        }
        if (dfn[p] == low[p]) {
            component.push_back({});
            int node;
            do {
                node = s.top();
                s.pop();
                instack[node] = false;
                component.back().push_back(node);
            } while (node != p);
        }
    };
    tarjan(tarjan, 1);
    return component;
}

class DSU {
private:
    std::vector<int> f, siz;
public:
    DSU(int n):f(n + 1),siz(n + 1, 1) {
        for(int i = 1; i <= n; i++) f[i] = i;
    }
    int find(int x){ return x == f[x] ? x : f[x] = find(f[x]); }
    bool same(int x,int y){ return find(x) == find(y); }
    void merge(int x,int y) {
        if(!same(x, y)) siz[find(y)] += siz[find(x)], f[find(x)] = find(y);
    }
    int qsz(int x){ return siz[find(x)]; }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    vec<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    vec<vec<int>> v(n + 1);
    for(int i = 1; i <= m; ++i) {
        int a, b;
        std::cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    auto it = Tarjan(v);
    vec<int> val(it.size());
    DSU T(n + 1);
    for(int i = 0; i < it.size(); ++i) {
        for(auto j:it[i]) val[i] += a[j], T.merge(j, it[i].front());
    }
    vec<vec<int>> G(n + 1);
    for(int i = 1; i <= n; ++i) {
        for(auto j:v[i]) {
            if(!T.same(i, j)) G[i].pb(j);
        }
    }
    vec<int> ans(n + 1);
    auto dfs = [&](auto self, int p) ->void {

    } ;

}