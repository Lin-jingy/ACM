#include <bits/stdc++.h>

#if defined (_WIN64)
#pragma clang diagnostic ignored "-Wunused-value"
// #pragma clang diagnostic ignored "-Wshift-op-parentheses"
#endif
#define int long long
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

// int n, c;
// int a[1005], pre[1005];
// int mx = 0;

// void dfs(int p, int sum) {
//     if(sum > c) return ;
//     if(sum > mx) mx = sum;
//     if(p == n + 1) return ;
//     for(int i = p; i <= n; ++i) {
//         dfs(i + 1, sum + a[i]);
//     }
// }

// void solve() {
//     std::cin >> n >> c;
//     for(int i = 1; i <= n; ++i) std::cin >> a[i], pre[i] = pre[i - 1] + a[i];
//     dfs(1, 0);
//     std::cout << mx;
// }

void solve() {
    int n, c;
    std::cin >> n >> c;
    vec<int> a(n);
    std::cin >> a;
    std::random_shuffle(a.begin(), a.end());
    int k = n / 2;
    vec<int> L, R;
    L.pb(0), R.pb(0);
    for(int i = 0; i < k; ++i) {
        int len = L.size();
        for(int j = 0; j < len; ++j) L.pb(L[j] + a[i]);
    }
    for(int i = k; i < n; ++i) {
        int len = R.size();
        for(int j = 0; j < len; ++j) R.pb(R[j] + a[i]);
    }
    std::sort(All(R));
    int mx = 0;
    for(auto i:L) {
        auto it = std::upper_bound(All(R), c - i);
        if(it == R.begin()) continue;
        it = std::prev(it);
        mx = std::max(mx, *it + i);
    }
    std::cout << mx;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}
