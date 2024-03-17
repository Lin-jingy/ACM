#include <bits/stdc++.h>

#if defined (_WIN64)
#pragma clang diagnostic ignored "-Wunused-value"
// #pragma clang diagnostic ignored "-Wshift-op-parentheses"
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
#define inf = INT_MAX
#define INF = LONG_LONG_MAX;
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


void solve() {
    int n, l;
    std::cin >> n >> l;
    vec<Pii> v(n);
    rep(i, 0, n) std::cin >> v[i].first >> v[i].second;
    sort(v, [&](Pii a, Pii b) {
        return a.second < b.second;
    });

    vec<int> P;
    P.pb(0);
    for(auto i:v) P.pb(i.first), P.pb(i.second);
    sort(P);
    P.erase(std::unique(All(P)), P.end());

    int N = P.size();
    vec<int> f(N << 2), a(N << 2);
    auto pushUp = [&](int p) {
        f[p] = f[p << 1] + f[p << 1 | 1];
        a[p] = a[p << 1] + a[p << 1 | 1];
    };
    auto change = [&](auto &&self, int p, int l, int r, int d) ->void {
        if(l == r) {
            f[p] += d, a[p]++;
            return ;
        }
        int mid = (l + r) >> 1;
        if(d <= P[mid]) self(self, p << 1, l, mid, d);
        else self(self, p << 1 | 1, mid + 1, r, d);
        pushUp(p); 
    };
    auto get = [&](auto &&self, int p, int l, int r, int last) ->int {
        LOG(last >= 0);
        if(l == r) {
            return std::min(last / P[l], a[p]);
        }
        int mid = (l + r) >> 1; 
        LOG(mid >= 1 and mid <= N);
        if(f[p << 1] >= last) return self(self, p << 1, l, mid, last);
        else return a[p << 1] + self(self, p << 1 | 1, mid + 1, r, last - f[p << 1]);
    };

    int k = 0;
    rep(i, 0, n) {
        std::fill(All(a), 0);
        std::fill(All(f), 0);
        rep(j, i, n) {
            int L = l - v[j].second + v[i].second;
            if(L <= 0) break;
            change(change, 1, 1, N - 1, v[j].first);
            k = std::max(k, get(get, 1, 1, N - 1, L));
        }
    }
    std::cout << k << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
