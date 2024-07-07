#include <bits/stdc++.h>
#include <random>

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
using i128=__int128;constexpr int inf=INT_MAX;constexpr long long INF=LONG_LONG_MAX;template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;using Pii=std::pair<int,int>;template<class T>using vvec=std::vector<std::vector<T>>;template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;template<class T,size_t S>using arr=std::array<T,S>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};class Timer{private:std::chrono::system_clock::time_point begin;public:Timer(){begin=std::chrono::system_clock::now();}~Timer(){auto end=std::chrono::system_clock::now();auto time=std::chrono::duration<double,std::nano>(end-begin).count();std::clog<<"\nThe program takes: "<<time/1e9<<" s\n";}double get(){auto end=std::chrono::system_clock::now();auto time=std::chrono::duration<double,std::nano>(end-begin).count();return time/1e9;}};template<class...Ts>auto&print(Ts...ts){return((std::cout<<ts<<" "),...);}template<class...Ts>auto&Print_log(Ts...ts){return((std::clog<<ts<<" "),...);}template<class...Ts>auto&read(Ts&...ts){return((std::cin>>ts),...);}std::istream&operator>>(std::istream&in,__int128&value){std::string s;in>>s;value=0;bool op=0;std::ranges::reverse(s);if(s.back()=='-'){op=1;s.pop_back();}while(!s.empty())value=value*10+s.back()-'0',s.pop_back();if(op)value=-value;return in;}std::ostream&operator<<(std::ostream&out,const __int128&value){__int128 x=(value<0?-value:value);if(value<0)out<<'-';std::string s;while(x){s+=(char)(x%10+'0');x/=10;}std::ranges::reverse(s);out<<s;return out;}
void solve(int n, vec<int> a);
void solve1();
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int k = 6;
    // for(int i = 0; i <= k; ++i) {
    //     vec<int> a = {0};
    //     for(int j = 1; j <= i; ++j) a.pb(2);
    //     for(int j = i + 1; j <= k; ++j) a.pb(1);
    //     std::cout << k << ' ' << i << ' ';
    //     solve(k, a); 
    // }
    solve1();
    return 0;
}

const int N = 1000;
int f[N],SG[N],S[N];
void getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));
    for(i = 1; i <= n; i++){
        memset(S,0,sizeof(S));
        for(j = 0; f[j] <= i && j <= N; j++)
            S[SG[i-f[j]]] = 1;
        for(j = 0;; j++) if(!S[j]){
            SG[i] = j;
            break;
        }
    }
}

void solve(int n, vec<int> a) {
    for(int i = 1; i < N; ++i) f[i] = i;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        getSG(a[i]);
        ans ^= SG[a[i]];
    }
    std::cout << ans << '\n';

}

void solve1() {
    int n;
    std::cin >> n;
    vec<int> a(n);
    std::cin >> a;
    if(n == 1) {
        std::cout << std::format("{} {}\n{}\n", a[0], 1, 0);
        return ;
    } 
    int k = 0;
    for(auto i:a) k ^= i;
    if(k == 0) {
        std::cout << "lose";
        return; 
    }
    for(int i = 0; i < n; ++i) {
        if((k ^ a[i]) <= a[i]) {
            std::cout << std::format("{} {}\n", a[i] - (k ^ a[i]), i + 1);
            a[i] ^= k;
            break;
        }
    }
    for(int i = 0; i < n; ++i) std::cout << a[i] << ' ';
}