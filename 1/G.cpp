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
int cir;

double dis(Pii a, Pii b) {
    int d = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    return std::sqrt(d);
}
bool is(Pii a, Pii b) {
    int dis = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    return dis <= cir;
}

static std::vector<double> Dijkstra(std::vector<std::vector<std::pair<int, double>>> *v, int begin) {
    std::vector<double> dis(v->size(), 1e18);
    std::vector<bool> vis(v->size());
    std::priority_queue<std::pair<double, int>,
                        std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>>
        q;
    dis[begin] = 0;
    q.push({0, begin});
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        double ds = it.first;
        int pos = it.second;
        if (vis[pos]) continue;
        vis[pos] = true;
        for (auto i : (*v)[pos]) {
            int p = i.first;
            double k = i.second;
            if (ds + k < dis[p]) {
                dis[p] = ds + k;
                q.push({dis[p], p});
            }
        }
    }
    return std::move(dis);
}

void solve() {
    int n;
    std::cin >> n;
    vec<Pii> p(n);
    rep(i, 0, n) std::cin >> p[i].first >> p[i].second;
    Pii begin, end;
    std::cin >> begin.first >> begin.second >> end.first >> end.second;
    int speed1, speed2;
    std::cin >> speed1 >> speed2;
    vec<vec<std::pair<int, double>>> v(n + 10);
    p.push_back(begin);
    p.push_back(end);
    rep(i, 0, p.size() - 2) {
        double d = dis(p[i], p[p.size() - 2]);
        v[p.size() - 2].push_back({i, d / speed1});
        v[i].push_back({p.size() - 2, d / speed1});
    }
    rep(i, 0, p.size() - 2) {
        double d = dis(p[i], p[p.size() - 1]);
        v[p.size() - 1].push_back({i, d / speed1});
        v[i].push_back({p.size() - 1, d / speed1});
    }
    cir = (3 * speed2) * (3 * speed2);
    rep(i, 0, (int)p.size() - 2) {
        rep(j, 0, (int)p.size()) {
            if(j == p.size() - 2) continue;
            if(i == j) continue;
            double d = dis(p[i], p[j]);
            if(is(p[i], p[j])) {
                v[i].push_back({j, d / speed2});
                v[j].push_back({i, d / speed2});
            } else {
                v[i].push_back({j, (d - speed2 * 3) / speed1 + 3});
                v[j].push_back({i, (d - speed2 * 3) / speed1 + 3});
            }
            // log(i, j);
        }
    }
    v[p.size() - 2].push_back({p.size() - 1, dis(p[p.size() - 2], p[p.size() - 1]) / speed1});
    v[p.size() - 1].push_back({p.size() - 2, dis(p[p.size() - 2], p[p.size() - 1]) / speed1});
    // rep(i, 0, v.size()) {
    //     for(auto [j, k]: v[i]) std::cout << i << ' ' << j << ' ' << k << '\n';
    // }
    vec<double> D = Dijkstra(&v, p.size() - 2);
    // log(dis.size());
    printf("%.12lf", D[p.size() - 1]);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}
