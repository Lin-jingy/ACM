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
    std::deque<int>q;
    std::vector<int>a(n);
    for(int i(0); i < n; ++i) std::cin >> a[i];
    std::sort(ALL(a));
    for(auto i:a) q.push_back(i);
    int ans(0);
    while(q.size() > 1) {
        ans += (q.back() - q.front());
        q.pop_back(); 
        q.pop_front();
    }
    std::cout << ans << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
