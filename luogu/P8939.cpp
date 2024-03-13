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
return out;}template<class T,class FUN>void foreach
(std::vector<T>&v,FUN fun){for(int i=0;i<v.size();++i)fun(v[i],i);}
template <class T>void Sort(std::vector<T>&v) {std::sort(v.begin(),v.end());}
using Pii = std::pair<int, int>;using i128 = __int128;
#define rep(i,b,e) for(int i=b;i<(int)(e);++i)
#define range(i,b,e,step) for(int i=b;(b<e?i<e:i>e);i+=(b<e?step:-step))
#define RETURN(x) do{return x,void();}while(0);
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf = INT_MAX
#define INF = LONG_LONG_MAX;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::multiset<int> s;
    rep(i, 0, n) {
        int x;
        std::cin >> x;
        s.insert(x);
    }
    while(q--) {
        int op, x;
        std::cin >> op >> x;
        if(op == 1) {
            if(s.count(x)) {
                s.erase(s.find(x));
                std::cout << (*s.rbegin() - *s.begin()) * 2 << '\n';
            } else {
                std::cout << "-1\n";
            }
        } else {
            s.insert(x);
            std::cout << (*s.rbegin() - *s.begin()) * 2 << '\n';
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
