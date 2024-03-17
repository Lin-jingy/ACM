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

void solve() {
    int n;
    std::cin >> n;
    std::array<std::string, 2> a;
    std::cin >> a[0] >> a[1];
    a[0] = ' ' + a[0];
    a[1] = ' ' + a[1];
    vec<vec<vec<int>>> dp(2, vec<vec<int>>(n + 1, vec<int>(2)));
    dp[0][1][0] = 1;
    for(int i = 1; i <= n; ++i) {
        dp[0][i][1] |= dp[0][i - 1][0];
        if(a[0][i - 1] == '>') dp[0][i][0] |= dp[0][i - 1][1];
        dp[1][i][1] |= dp[1][i - 1][0];
        if(a[1][i - 1] == '>') dp[1][i][0] |= dp[1][i - 1][1];
        dp[1][i][1] |= dp[0][i][0];
        dp[0][i][1] |= dp[1][i][0];
    }
    if((dp[1][n][1] | dp[1][n][0]) == 1) std::cout << "YES\n";
    else std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
