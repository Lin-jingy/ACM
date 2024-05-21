#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

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
    int n, m, k;
    std::cin >> n >> m >> k;
    vec<int> a(n), d(m), f(k);
    std::cin >> a >> d >> f;
    int l = a[0], r = a[1];
    rep(i, 1, a.size()) if(a[i] - a[i - 1] > r - l) r = a[i], l = a[i - 1];
    std::priority_queue<int> Q;
    rep(i, 1, a.size()) Q.push(a[i] - a[i - 1]);
    Q.pop();
    int ans = r - l;
    std::ranges::sort(f);
    f.erase(std::unique(All(f)), f.end());
    rep(i, 0, d.size()) {
        int last_l = l - d[i];
        int last_r = r - d[i];
        if(d[i] + f.front() > r or d[i] + f.back() < l) continue;
        int L = std::upper_bound(All(f), last_l) - f.begin();
        int R = std::lower_bound(All(f), last_r) - f.begin();
        --R;
        int k = r - l;
        while(L <= R) {
            int mid = (L + R) >> 1;
            int val = std::max(r - (f[mid] + d[i]), (f[mid] + d[i]) - l);
            if(val < k) k = val;
            if(mid == R) {
                int vall = std::max(r - (f[mid - 1] + d[i]), (f[mid - 1] + d[i]) - l);
                if(vall > val) L = mid + 1;
                else R = mid - 1;
            }
            else {
                int valr = std::max(r - (f[mid + 1] + d[i]), (f[mid + 1] + d[i]) - l);
                if(valr < val) L = mid + 1;
                else R = mid - 1;
            }
        }
        ans = std::min(ans, k);
    }
    Q.push(ans);
    std::cout << Q.top() << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
