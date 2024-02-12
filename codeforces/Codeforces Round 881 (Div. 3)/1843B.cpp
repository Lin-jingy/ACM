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
    int n;
    std::cin >> n;
    std::vector<int>a(n + 1);
    int sum(0), k(0);
    for(int i(1); i <= n; ++i) std::cin >> a[i], sum += abs(a[i]);
    std::cout << sum << ' ';
    std::vector<int>p;
    p.push_back(1);
    for(auto i:a) if(i != 0) p.push_back(i);
    for(int i = 1; i < p.size(); ++i) if(p[i] < 0 and p[i - 1] > 0) ++k;
    std::cout << k << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
