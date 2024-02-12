// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"


void solve(){
    int n, k;
    std::cin >> n >> k;
    std::vector<PII>a(n);
    for(size_t i(0); i < n; ++i) {
        std::cin >> a[i].first, a[i].second = i;
        a[i].first %= k;
        if(a[i].first == 0) a[i].first = k;
    }
    std::sort(ALL(a), [&](PII x, PII y){
        if(x.first != y.first) return x.first > y.first;
        else return x.second < y.second;
    });
    for(auto i:a) std::cout << i.second + 1 << ' ';
    std::cout << '\n';

}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
