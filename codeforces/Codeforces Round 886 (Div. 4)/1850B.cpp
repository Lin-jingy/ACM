// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int n;
    std::cin >> n;
    std::vector<PII>a(n);
    for(size_t i(0); i < n; ++i) std::cin >> a[i].second >> a[i].first;
    int mx(0), t(0);
    for(size_t i(0); i < n; ++i){
        if(a[i].second <=10 and a[i].first > mx) mx = a[i].first, t = i + 1;
    }
    std::cout << t << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
