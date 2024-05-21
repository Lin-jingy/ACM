#include <bits/stdc++.h>

// #define int long long
#define rep(i,b,e)for(int i=b;i<e;++i)
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x)emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX
template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}using Pii=std::pair<int,int>;template<class T>using vvec=std::vector<std::vector<T>>;template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;
#define vec(type,x,sz,val)std::vector<type>x(sz,val);
#define vvec(type,x,sz1,sz2,val)std::vector<std::vector<type>>x(sz1,std::vector<type>(sz2,val));
#if defined(_WIN64)
#define log(...)print(#__VA_ARGS__" ::",__VA_ARGS__)<<std::endl
template<class...Ts>auto&print(Ts...ts){return((std::cerr<<ts<<" "),...);}
#define sure(x)if(!(x)){std::cerr<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define sure(x)111
#define log(...)111
#endif

int ch(char op) {
    switch (op) {
        case 'N': return 0;
        case 'E': return 1;
        case 'S': return 2;
        case 'W': return 3;
    }
    return 0;
}


void solve() {
    int n, m;
    std::cin >> n >> m;
    vvec(int, v, n + 1, m + 1, 0);
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            std::cin >> v[i][j];
        }
    }
    Pii begin, end;
    char op;
    std::cin >> begin >> end >> op;
    std::queue<std::array<int, 4>> q;
    vec<vec<std::array<int, 4>>> mn(n + 1, vec<std::array<int, 4>>(m + 1, {inf, inf, inf, inf})); 
    q.push({0, begin.first, begin.second, ch(op)});
    while(!q.empty()) {
        auto [dis, x, y, op] = q.front();
        q.pop();
        if(x <= 0  or x >= n or y <= 0 or y >= m or mn[x][y][op] < dis) continue;
        mn[x][y][op] = dis;
        if(mn[x][y][(op + 1) % 4] > dis + 1) q.push({dis + 1, x, y, (op + 1) % 4});
        if(mn[x][y][(op + 3) % 4] > dis + 1) q.push({dis + 1, x, y, (op + 3) % 4});
        int rx, ry;
        if(op == 0) rx = -1, ry = 0;
        else if(op == 1) rx = 0, ry = 1;
        else if(op == 2) rx = 1, ry = 0;
        else rx = 0, ry = -1;
        for(int i = 1; i <= 3; ++i) {
            int X = x + rx * i, Y = y + ry * i;
            if(X <= 0  or X >= n or Y <= 0 or Y >= m) break;
            if(v[X][Y] != 1 and v[X][Y + 1] != 1 and v[X + 1][Y] != 1 and v[X + 1][Y + 1] != 1) {
                if(mn[X][Y][op] > dis + 1) q.push({dis + 1, X, Y, op});
            } else {
                break;
            }
        }
    }
    int ans = inf;
    rep(i, 0, 4) ans = std::min(ans, mn[end.first][end.second][i]);
    if(ans >= 1e5) std::cout << "-1\n";
    else std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
