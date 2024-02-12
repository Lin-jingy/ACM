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
    int n, k;
    std::cin >> n >> k;
    std::vector<int>a(n);
    for(size_t i(0); i < n; ++i) std::cin >> a[i];
    std::sort(ALL(a));
    std::stack<int>s;
    int ans(0);
    for(size_t i(0); i < n; ++i){
        if(s.empty() or a[i] - s.top() <= k) s.push(a[i]);
        else{
            ans = std::max(ans, (int)s.size());
            while(!s.empty()) s.pop();
            s.push(a[i]);
        } 
    }
    ans = std::max(ans, (int)s.size());
    std::cout << n - ans << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
