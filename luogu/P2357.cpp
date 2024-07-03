#include <bits/stdc++.h>

#if __GNUC__ && __has_include(<iconv.h>)
#include <bits/extc++.h>
template<class _KEY,class _Compare=std::less<_KEY>>using pbds_set=__gnu_pbds::tree<_KEY,__gnu_pbds::null_type,_Compare,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;template<class _KEY,class _VALUE,class _Compare=std::less<_KEY>>using pbds_map=__gnu_pbds::tree<_KEY,_VALUE,_Compare,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
#endif

#define int long long
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x...)emplace_back(x)
#define fmt(x...)std::format(x)
#define logs(x...)Print_log(#x" ::",x)<<std::endl
#define ensure(x)if(!(x)){std::cerr<<"ensure error:("<<#x<<")->at line:"<<__LINE__<<std::endl;exit(-1);}
using i128=__int128;constexpr int inf=INT_MAX;constexpr long long INF=LONG_LONG_MAX;template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;using Pii=std::pair<int,int>;template<class T>using vvec=std::vector<std::vector<T>>;template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;template<class T,size_t S>using arr=std::array<T,S>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};class Timer{private:std::chrono::system_clock::time_point begin;public:Timer(){begin=std::chrono::system_clock::now();}~Timer(){auto end=std::chrono::system_clock::now();auto time=std::chrono::duration<double,std::nano>(end-begin).count();std::clog<<"\nThe program takes: "<<time/1e9<<" s\n";}double get(){auto end=std::chrono::system_clock::now();auto time=std::chrono::duration<double,std::nano>(end-begin).count();return time/1e9;}};template<class...Ts>auto&print(Ts...ts){return((std::cout<<ts<<" "),...);}template<class...Ts>auto&Print_log(Ts...ts){return((std::clog<<ts<<" "),...);}template<class...Ts>auto&read(Ts&...ts){return((std::cin>>ts),...);}std::istream&operator>>(std::istream&in,__int128&value){std::string s;in>>s;value=0;bool op=0;std::ranges::reverse(s);if(s.back()=='-'){op=1;s.pop_back();}while(!s.empty())value=value*10+s.back()-'0',s.pop_back();if(op)value=-value;return in;}std::ostream&operator<<(std::ostream&out,const __int128&value){__int128 x=(value<0?-value:value);if(value<0)out<<'-';std::string s;while(x){s+=(char)(x%10+'0');x/=10;}std::ranges::reverse(s);out<<s;return out;}
void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
class SegmentTree {
private:
    struct Treenode { int f, tag; };
    std::vector<Treenode> v;
    std::vector<int> *a;
    int n;
#define f(x) (v[x].f)
#define tag(x) (v[x].tag)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void pushDown(int p, int l, int r) {
        if (!tag(p)) return;
        int mid = (l + r) >> 1;
        f(ls(p)) += tag(p) * (mid - l + 1);
        f(rs(p)) += tag(p) * (r - mid);
        tag(ls(p)) += tag(p);
        tag(rs(p)) += tag(p);
        tag(p) = 0;
    }
    void pushUp(int p) {
        f(p) = f(ls(p)) + f(rs(p));
    }
    void build(int p, int l, int r) {
        if (l == r) {
            f(p) = (*a)[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(p), l, mid);
        build(rs(p), mid + 1, r);
        pushUp(p);
    }
    void Update(int p, int l, int r, int i, int j, int d) {
        if (i <= l and j >= r) {
            tag(p) = tag(p) + d;
            f(p) = f(p) + d * (r - l + 1);
            return;
        }
        pushDown(p, l, r);
        int mid = (l + r) >> 1;
        if (i <= mid) Update(ls(p), l, mid, i, j, d);
        if (j > mid) Update(rs(p), mid + 1, r, i, j, d);
        pushUp(p);
    }
    int Query(int p, int l, int r, int i, int j) {
        if (i <= l and j >= r) return f(p);
        pushDown(p, l, r);
        int mid = (l + r) >> 1, sum = 0;
        if (i <= mid) sum += Query(ls(p), l, mid, i, j);
        if (j > mid) sum += Query(rs(p), mid + 1, r, i, j);
        return sum;
    }

public:
    SegmentTree(int N, std::vector<int> *A) : n(N), v(N << 2), a(A){ build(1, 1, n);}
    void update(int l, int r, int d) { Update(1, 1, n, l, r, d); }
    int query(int i, int j) { return Query(1, 1, n, i, j); }
#undef f
#undef tag
#undef ls
#undef rs

};

void solve() {
    int n, f;
    std::cin >> n >> f;
    vec<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    SegmentTree T(n, &a);
    while(f--) {
        int op;
        std::cin >> op;
        if(op == 1) {
            int l, r, k;
            std::cin >> l >> r >> k;
            T.update(l, r, k);
        } else if(op == 2) {
            int k;
            std::cin >> k;
            T.update(1, 1, k);
        } else if(op == 3) {
            int k;
            std::cin >> k;
            T.update(1, 1, -k);
        } else if(op == 4) {
            int l, r;
            std::cin >> l >> r;
            std::cout << T.query(l, r) << '\n';
        } else {
            std::cout << T.query(1, 1) << '\n';
        }
    }
}