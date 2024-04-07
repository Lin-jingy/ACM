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

int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    vec<vec<char>> v(n + 10, vec<char>(m + 10));
    Pii begin, end;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            std::cin >> v[i][j];
            if(v[i][j] == 'S') begin = {i, j}, v[i][j] = '.';
            else if(v[i][j] == 'T') end = {i, j}, v[i][j] = '.';
        }
    }
    vec<vec<int>> a(n + 10, vec<int>(m + 10)), mx(n + 10, vec<int>(m + 10));
    int k;
    std::cin >> k;
    rep(i, 0, k) {
        int x, y, z;
        std::cin >> x >> y >> z;
        a[x][y] = z;
    }
    auto dfs = [&](auto &&self, int x, int y, int val) ->void {
        if(x == end.first and y == end.second) {
            std::cout << "Yes\n";
            exit(0);
        }
        if(v[x][y] != '.') return ;
        val = std::max(val, a[x][y]);
        if(val <= mx[x][y] or val == 0) return ;
        mx[x][y] = val;
        int mid = a[x][y];
        a[x][y] = 0;
        rep(i, 0, 4) {
            self(self, x + rx[i], y + ry[i], val - 1);
        }
        a[x][y] = mid;
    };
    int mid = a[begin.first][begin.second];
    a[begin.first][begin.second] = 0;
    dfs(dfs, begin.first, begin.second, mid);
    std::cout << "No";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}
