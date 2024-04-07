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
    int n;
    std::cin >> n;
    vec<int> a(n), p(n);
    std::cin >> a >> p;
    std::set<int> del;
    std::priority_queue<Pii> q;
    rep(i, 0, n) q.push({a[i], i + 1});
    std::set<Pii> op;
    op.insert(q.top());
    int ans = op.begin()->first, sz = 1;
    q.pop();
    rep(i, 1, n) {
        del.insert(p[i - 1]);
        A:;
        while(!q.empty() and del.count(q.top().second)) q.pop();
        if(q.empty()) break;
        op.insert(q.top());
        q.pop();
        if(op.count({a[p[i - 1] - 1], p[i - 1]})) {
            op.erase({a[p[i - 1] - 1], p[i - 1]});
            goto A;
        }
        if(op.begin()->first * (int)op.size() > ans) {
            ans = op.begin()->first * (int)op.size();
            sz = op.size();
        }
        if(q.empty()) break;
    }
    std::cout << ans << ' ' << sz << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
