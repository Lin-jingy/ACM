#include <bits/stdc++.h>

#if __GNUC__ && __has_include(<iconv.h>)
#include <bits/extc++.h>
template<class _KEY,class _Compare=std::less<_KEY>>using pbds_set=__gnu_pbds::tree<_KEY,__gnu_pbds::null_type,_Compare,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;template<class _KEY,class _VALUE,class _Compare=std::less<_KEY>>using pbds_map=__gnu_pbds::tree<_KEY,_VALUE,_Compare,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
#endif

// #define int long long
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x...)emplace_back(x)
#define fmt(x...)std::format(x)
#define logs(x...)Print_log(#x" ::",x)<<std::endl
#define ensure(x)if(!(x)){std::cerr<<"ensure error:("<<#x<<")->at line:"<<__LINE__<<std::endl;exit(-1);}
using i128=__int128;constexpr int inf=INT_MAX;constexpr long long INF=LONG_LONG_MAX;template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;using Pii=std::pair<int,int>;template<class T>using vvec=std::vector<std::vector<T>>;template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;template<class T,size_t S>using arr=std::array<T,S>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};class Timer{private:std::chrono::system_clock::time_point begin;public:Timer(){begin=std::chrono::system_clock::now();}double get(){auto end=std::chrono::system_clock::now();auto time=std::chrono::duration<double,std::nano>(end-begin).count();return time/1e9;}};template<class...Ts>auto&print(Ts...ts){return((std::cout<<ts<<" "),...);}template<class...Ts>auto&Print_log(Ts...ts){return((std::clog<<ts<<" "),...);}template<class...Ts>auto&read(Ts&...ts){return((std::cin>>ts),...);}std::istream&operator>>(std::istream&in,__int128&value){std::string s;in>>s;value=0;bool op=0;std::ranges::reverse(s);if(s.back()=='-'){op=1;s.pop_back();}while(!s.empty())value=value*10+s.back()-'0',s.pop_back();if(op)value=-value;return in;}std::ostream&operator<<(std::ostream&out,const __int128&value){__int128 x=(value<0?-value:value);if(value<0)out<<'-';std::string s;while(x){s+=(char)(x%10+'0');x/=10;}std::ranges::reverse(s);out<<s;return out;}
void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
str a, b;
umap<str, str> mp1;
umap<str, vec<str>> mp2;
int ans = 20;
umap<str, int> ans1;
Timer T;
void dfs(int dep, str x) {
    if(ans1.count(x)) ans1[x] = std::min(ans1[x], dep);
    else ans1[x] = dep;
    if(dep == 5 or x.size() > 20) return ; 
    if(x == b) ans = std::min(ans, dep);
    for(auto &[i, j] : mp1) {
        for(int k = 0; k < x.size(); ++k) {
            auto pos = x.find(i, k);
            if(pos == std::string::npos) continue;
            std::string mid = x;
            mid.replace(pos, i.size(), j);
            dfs(dep + 1, mid);
        }
    }
}

void dfs2(int dep, str x) {
    if(T.get() > 0.7) return ;
    if(ans1.count(x)) ans = std::min(ans, ans1[x] + dep);
    if(dep == 5 or x.size() > 20) return ; 
    if(x == a) ans = std::min(ans, dep);
    for(auto &[i, ve] : mp2) {
        for(auto &j:ve) {
            for(int k = 0; k < x.size(); ++k) {
                auto pos = x.find(i, k);
                if(pos == std::string::npos) continue;
                std::string mid = x;
                mid.replace(pos, i.size(), j);
                dfs2(dep + 1, mid);
            }
        }
        
    }
}

void solve() {
    std::cin >> a >> b;
    str x, y;
    while(std::cin >> x >> y) mp1[x] = y, mp2[y].pb(x);
    dfs(0, a);
    dfs2(0, b);
    if(ans == 20) std::cout << "NO ANSWER!";
    else std::cout << ans;
}