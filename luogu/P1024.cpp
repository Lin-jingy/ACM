#include <bits/stdc++.h>

#if defined (_WIN64)
#pragma clang diagnostic ignored "-Wunused-value"
// #pragma clang diagnostic ignored "-Wshift-op-parentheses"
#endif
// #define int long long
template <class T>using vec=std::vector<T>;
template<class K,class V> using umap=std::unordered_map<K,V>;
template<class T>std::istream& operator>>(std::istream& in,std::vector<T>& v) 
{for(auto &i: v)in>>i;return in;}template<class T>std::ostream& 
operator<<(std::ostream& out, const std::vector<T>& v) {
for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];
return out;}template<class T>void foreach(std::vector<T>&v,
std::function<void(T&,int)>fun){for(int i=0;i<v.size();++i)fun(v[i],i);}
template<class T,class FUN>void foreach(std::vector<T>&v,FUN fun)
{for(int i=0;i<v.size();++i)fun(v[i],i);}
using Pii = std::pair<int, int>;using i128 = __int128;
#define RETURN(x) do{return(x),void();}while(0);
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf = INT_MAX
#define INF = LONG_LONG_MAX;


void solve() {
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    vec<double> ans;
    for(double i = -100; i <= 100; i += 0.001) {
        double j = i + 0.001;
        double l = a * i * i * i + b * i * i + c * i + d;
        double r = a * j * j * j + b * j * j + c * j + d;
        if((l >= 0) ^ (r >= 0)) {
            printf("%.2lf ", i);
        }
    }



}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}
