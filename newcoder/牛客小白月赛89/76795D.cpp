#include <bits/stdc++.h>

#if defined (_WIN64)
#define LOG(x) if(!(x)){std::cout<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define LOG(x)
#endif
#define int long long
#define rep(i,b,e) for(int i=b;i<(int)(e);++i)
#define range(i,b,e,step) for(int i=b;(b<e?i<e:i>e);i+=(b<e?step:-step))
#define RETURN(x) do{return x,void();}while(0);
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX;
template <class T>using vec=std::vector<T>;
template<class K,class V> using umap=std::unordered_map<K,V>;
template<class T>std::istream& operator>>(std::istream&in,std::vector<T>&v) 
{for(auto &i:v)in>>i;return in;}template<class T>std::ostream& 
operator<<(std::ostream&out,const std::vector<T>&v) {
for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];
return out;}template<class T,class FUN>void foreach
(std::vector<T>&v,FUN fun){for(int i=0;i<v.size();++i)fun(v[i],i);}
template <class T>void sort(std::vector<T>&v) {std::sort(v.begin(),v.end());}
template <class T,class FUN>void sort(std::vector<T>&v,FUN fun) 
{std::sort(v.begin(),v.end(),fun);}template<class T>void input
(T begin,T end){while(begin!=end)std::cin>>*begin++;}
using Pii = std::pair<int, int>;
static std::vector<int> Dijkstra(std::vector<std::vector<std::pair<int, int>>> *v, int begin) {
    std::vector<int> dis(v->size());
    std::vector<bool> vis(v->size());
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
        q;
    dis[begin] = 0;
    q.push({0, begin});
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int ds = it.first, pos = it.second;
        if (vis[pos]) continue;
        vis[pos] = true;
        for (auto i : (*v)[pos]) {
            int p = i.first;
            int k = i.second;
            if (ds + k < dis[p]) {
                dis[p] = ds + k;
                q.push({dis[p], p});
            }
        }
    }
    return std::move(dis);
}
constexpr int mod = 1e9 + 7;
constexpr int N = 5005;
constexpr int qpow(int a, int b) {
    int sum = 1;
    while(b) {
        if(b & 1) sum = sum * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return sum;
}
int inv[N], cal[N];
int C(int a, int b) {
    if(b > a) return 0;
    if(a == b or b == 0) return 1;
    return cal[a] * inv[b] % mod * inv[a - b] % mod;
}
void solve() {
    int n, m, q, x;
    std::cin >> n >> m >> q >> x;
    vec<vec<Pii>> v(n + 1);
    rep(i, 0, m) {
        int a, b;
        std::cin >> a >> b;
        v[b].push_back({a, 1});
        v[a].push_back({b, 1});
    }
    vec<int> dis = Dijkstra(&v, x);
    std::map<int, int> mp;
    rep(i, 1, dis.size()) if(i != x) mp[dis[i]]++;
    while(q--) {
        int k;
        std::cin >> k;
        int ans = 0;
        int tot = n - 1;
        for(auto [i, j] : mp) {
            ans += C(tot, k - 1) * j % mod;
            ans %= mod;
        }
        std::cout << ans << '\n';

    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    cal[0] = 1, inv[0] = 1;
    rep(i, 1, N) cal[i] = cal[i - 1] * i % mod, inv[i] = qpow(cal[i], mod - 2);
    // std::cin >> T;
    while(T--) solve();
    return 0;
}

/*
1 2 3 4 5

123
124
125
134
135
145
234
235
245
345

*/
