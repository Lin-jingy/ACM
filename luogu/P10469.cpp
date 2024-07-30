#include <bits/stdc++.h>

#if __GNUC__
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
template<class _KEY,class _Compare=std::less<_KEY>>using pbds_set=__gnu_pbds::tree<_KEY,__gnu_pbds::null_type,_Compare,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;template<class _KEY,class _VALUE,class _Compare=std::less<_KEY>>using pbds_map=__gnu_pbds::tree<_KEY,_VALUE,_Compare,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;template<class T,class Comp=std::less<T>>using pbds_heap=__gnu_pbds::priority_queue<T,Comp,__gnu_pbds::pairing_heap_tag>;
#endif
#if __SIZEOF_POINTER__==8&&__GNUC__&&__cplusplus>=202002L
using i128=__int128;std::istream&operator>>(std::istream&in,__int128&value){std::string s;in>>s;value=0;bool op=0;std::ranges::reverse(s);if(s.back()=='-'){op=1;s.pop_back();}while(!s.empty())value=value*10+s.back()-'0',s.pop_back();if(op)value=-value;return in;}std::ostream&operator<<(std::ostream&out,const __int128&value){__int128 x=(value<0?-value:value);if(value<0)out<<'-';std::string s;while(x){s+=(char)(x%10+'0');x/=10;}std::ranges::reverse(s);out<<s;return out;}template<class...Args>void print(const std::string_view&fmtStr,Args&&...args){std::cout<<std::vformat(fmtStr,std::make_format_args(args...));}
#endif
template<class T,class A=std::allocator<T>>class vector:public std::vector<T,A>{public:constexpr vector()noexcept(noexcept(A())):std::vector<T,A>(){}constexpr explicit vector(const A&alloc)noexcept:std::vector<T,A>(alloc){}constexpr vector(size_t count,const T&value=T(),const A&alloc=A()):std::vector<T,A>(count,value,alloc){}template<class InputIt>constexpr vector(InputIt first,InputIt last,const A&alloc=A()):std::vector<T,A>(first,last,alloc){}constexpr vector(const vector&other,const A&alloc=A()):std::vector<T,A>(other,alloc){}constexpr vector(vector&&other,const A&alloc=A()):std::vector<T,A>(other,alloc){}constexpr vector(std::initializer_list<T>init,const A&alloc=A()):std::vector<T,A>(init,alloc){}T&operator[](size_t pos){return this->at(pos);}const T&operator[](size_t pos)const{return this->at(pos);}};
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x...)emplace_back(x)
#define fmt(x...)std::format(x)
#define logs(x...)Print_log(#x" ::",x)<<std::endl
#define ensure(x)if(!(x)){std::cerr<<"ensure error:("<<#x<<")->at line:"<<__LINE__<<std::endl;exit(-1);}
constexpr int inf=INT_MAX;constexpr long long INF=LONG_LONG_MAX;template<class T>using vec=vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;using Pii=std::pair<int,int>;template<class T>using vvec=vector<vector<T>>;template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;template<class T,size_t S>using arr=std::array<T,S>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};template<bool print=false>class Timer{private:std::chrono::system_clock::time_point begin;public:Timer(){begin=std::chrono::system_clock::now();}~Timer(){if constexpr(print){auto end=std::chrono::system_clock::now();auto time=std::chrono::duration<double,std::nano>(end-begin).count();std::clog<<"\nThe program takes: "<<time/1e9<<" s\n";}}double get(){auto end=std::chrono::system_clock::now();auto time=std::chrono::duration<double,std::nano>(end-begin).count();return time/1e9;}};template<class...Ts>auto&Print_log(Ts...ts){return((std::clog<<ts<<" "),...);}
void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    str s;
    std::cin >> s;
    int n = s.size();
    s = ' ' + s;
    vec<int> sa(n + 1), rk((n + 1) << 1);
    for(int i = 1; i <= n; ++i) sa[i] = i, rk[i] = s[i] - 'a';
    for(int w = 1; w < n; w <<= 1) {
        std::sort(sa.begin() + 1, sa.end(), [&](int x, int y) {
            return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y]; 
        });
        auto oldrk = rk;
        for(int i = 1, p = 0; i <= n; ++i) {
            if (oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) 
                rk[sa[i]] = p;
            else rk[sa[i]] = ++p;
        }
    }
    vec<int> height(n + 1);
    for (int i = 1, k = 0; i <= n; ++i) {
        if (rk[i] == 0) continue;
        if (k) --k;
        while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
        height[rk[i]] = k;
    }
    
    for(int i = 1; i <= n; ++i) std::cout << sa[i] - 1 << ' ';
    std::cout << '\n';
    for(int i = 1; i <= n; ++i) std::cout << height[i] << ' ';
    std::cout << '\n';
}

// enum OPTION {
//     Nature,
//     Single,
//     Double,
// } ;
// template <enum OPTION op, long long base1 = 131, long long base2 = 133331>
// class StringHash {
//     #define int long long 
// private:
//     std::vector<int> hash1, hash2, p1, p2;
//     int mod1, mod2;
//     bool isprime(int n) {
//         if (n <= 1) return false;
//         for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
//         return true;
//     }
//     int findPrime(int n) {
//         while (!isprime(n)) n++;
//         return n;
//     }
//     void init_nature(const std::string &s) {
//         p1[0] = hash1[0] = 1;
//         for(int i = 1; i <= s.size(); ++i) {
//             hash1[i] = hash1[i - 1] * base1 + s[i - 1];
//             p1[i] = p1[i - 1] * base1;
//         }
//     }
//     void init_single(const std::string &s) {
//         p1[0] = hash1[0] = 1;
//         for(int i = 1; i <= s.size(); ++i) {
//             hash1[i] = (1LL * hash1[i - 1] * base1 + s[i - 1]) % mod1;
//             p1[i] = 1LL * p1[i - 1] * base1 % mod1;
//         }
//     }
//     void init_double(const std::string &s) {
//         hash2.resize(s.size() + 1);
//         p2.resize(s.size() + 1);
//         p1[0] = p2[0] = hash1[0] = hash2[0] = 1;
//         for(int i = 1; i <= s.size(); ++i) {
//             hash1[i] = (1LL * hash1[i - 1] * base1 + s[i - 1]) % mod1;
//             hash2[i] = (1LL * hash2[i - 1] * base2 + s[i - 1]) % mod2;
//             p1[i] = 1LL * p1[i - 1] * base1 % mod1;
//             p2[i] = 1LL * p2[i - 1] * base2 % mod2;
//         }
//     }
//     void init_mod() {
//         static int MOD1 = 0, MOD2 = 0;
//         if(!MOD1) {
//             std::mt19937_64 rnd(time(0));
//             MOD1 = findPrime(rnd() % 900'000'000 + 100'000'000);
//             MOD2 = findPrime(rnd() % 900'000'000 + 100'000'000);
//         }
//         mod1 = MOD1; mod2 = MOD2;
//     }
// public:
//     StringHash(const std::string &s): hash1(s.size() + 1), p1(s.size() + 1){
//         init_mod();
//         if constexpr (op == Nature) init_nature(s);
//         if constexpr (op == Single) init_single(s);
//         if constexpr (op == Double) init_double(s);
//     }
//     template <enum OPTION O = op>
//     std::enable_if_t<O == Nature, int> get(int l, int r) {
//         ++l, ++r;
//         return hash1[r] - hash1[l - 1] * p1[r - l + 1];
//     }
//     template <enum OPTION O = op>
//     std::enable_if_t<O == Single, int> get(int l, int r) {
//         ++l, ++r;
//         return (hash1[r] + (mod1 - hash1[l - 1]) * p1[r - l + 1]) % mod1;
//     }
//     template <enum OPTION O = op>
//     std::enable_if_t<O == Double, std::pair<int, int>> get(int l, int r) {
//         ++l, ++r;
//         return {(hash1[r] + 1LL * (mod1 - hash1[l - 1]) * p1[r - l + 1]) % mod1,
//         (hash2[r] + 1LL * (mod2 - hash2[l - 1]) * p2[r - l + 1]) % mod2};
//     }
//     template <enum OPTION O = op>
//     std::enable_if_t<O == Nature || O == Single, int> getAll() {
//         return hash1.back();
//     }
//     template <enum OPTION O = op>
//     std::enable_if_t<O == Double, std::pair<int, int>> getAll() {
//         return {hash1.back(), hash2.back()};
//     }
//     #undef int
// };

// void solve (){
//     str s;
//     std::cin >> s;
//     int n = s.size();
//     StringHash<Nature> T(s);
//     vec<int> sa(n), height(n);
//     for(int i = 0; i < n; ++i) sa[i] = i;
//     std::sort(sa.begin(), sa.end(), [&](int a, int b) {
//         int l = 1, r = n - std::max(a, b), ans = 0;
//         while(l <= r) {
//             int mid = (l + r) >> 1;
//             if(T.get(a, a + mid - 1) == T.get(b, b + mid - 1)) l = mid + 1, ans = mid;
//             else r = mid - 1;
//         }
//         return s[a + ans] < s[b + ans];
//     });
//     for(int i = 1; i < n; ++i) {
//         int a = sa[i], b = sa[i - 1];
//         int l = 1, r = n - std::max(a, b), ans = 0;
//         while(l <= r) {
//             int mid = (l + r) >> 1;
//             if(T.get(a, a + mid - 1) == T.get(b, b + mid - 1)) l = mid + 1, ans = mid;
//             else r = mid - 1;
//         }
//         height[i] = ans;
//     }
//     std::cout << sa << '\n' << height << '\n';
// }