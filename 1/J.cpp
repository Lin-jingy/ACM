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
#define log(x...) ;
#define sure(x) ;
#endif
using Pdd = std::pair<double, double>;
const double Pi = acos(-1.0);
const double g2 = std::sqrt(2);

double dis(Pdd a, Pdd b) {
    return std::sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
constexpr double eps = 1e-9;
int EPS(double x) {
    if(x >= eps) return 1;
    else if(x <= -eps) return -1;
    else return 0;
}
bool same(Pdd a, Pdd b) {
    if(std::abs(a.first - b.first) <= eps and std::abs(a.second - b.second) <= eps) return true;
    return false;
}
bool in(Pdd a) {
    if(a.first * a.first + a.second * a.second <= 1) return true;
    else return false;
}
void solve() {
    int x, y;
    std::cin >> x >> y;
    Pdd begin = {cos(Pi * x / 180), sin(Pi * x / 180)};
    Pdd end = {cos(Pi * y / 180), sin(Pi * y / 180)};
    vec<Pdd> ans;
    if(same(begin, end)) {
        printf("0\n%.10lf %.10lf\n", begin.first, begin.second);
        return ;
    }
    ans.pb(begin);
    auto fact = [&](Pdd B, Pdd E) ->void {
        double D = dis(B, E) / 2;
        double L = std::sqrt(1 - D * D);
        double dy = g2 / 2 * (L + D);
        double dx = std::sqrt(1 - dy * dy);
        int fx[] = {1, 1, -1, -1};
        int fy[] = {1, -1, 1, -1};
        rep(i, 0, 4) {
            if(EPS(dis({B.first + dx * fx[i], B.second + dy * fy[i]}, E) - 1) == 0 
            and EPS(dis({B.first + dx * fx[i], B.second + dy * fy[i]}, B) - 1) == 0
            and !in({B.first + dx * fx[i], B.second + dy * fy[i]})) {
                dx *= fx[i];
                dy *= fy[i];
                goto A;
            }
        }
        std::swap(dx, dy);
        rep(i, 0, 4) {
            if(EPS(dis({B.first + dx * fx[i], B.second + dy * fy[i]}, E) - 1) == 0 
            and EPS(dis({B.first + dx * fx[i], B.second + dy * fy[i]}, B) - 1) == 0
            and !in({B.first + dx * fx[i], B.second + dy * fy[i]})) {
                dx *= fx[i];
                dy *= fy[i];
                goto A;
            }
        }
        assert(false);
        A:;
        ans.push_back({B.first + dx, B.second + dy});
        ans.push_back(E);
    };
    if(EPS(dis(begin, end) - g2) > 0) {
        Pdd mid;
        double X, Y;
        if((begin.first >= 0 and end.first < 0) or (begin.first <= 0 and end.first > 0)) {
            X = (begin.first + end.first) / 2;
            Y = std::sqrt(1 - X * X);
        } else {
            Y = (begin.second + end.second) / 2;
            X = std::sqrt(1 - X * X);
        }
        fact(begin, {X, Y});
        begin = {X, Y};
    } 
    fact(begin, end);
    printf("%d\n", ans.size() - 1);
    for(auto [i, j] : ans) {
        printf("%.10lf %.10lf\n", i, j);
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
