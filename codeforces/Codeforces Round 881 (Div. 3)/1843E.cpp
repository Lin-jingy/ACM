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
    int n, m;
    std::cin >> n >> m;
    std::vector<PII>a(m + 1);
    for(int i(1); i <= m; ++i) std::cin >> a[i].first >> a[i].second;
    int q;
    std::cin >> q;
    std::vector<int>p(q + 1);
    for(int i(1); i <= q; ++i) std::cin >> p[i];
    auto check = [&](int x){
        std::vector<bool>vis(n + 1);
        for(int i = 1; i <= x; ++i) vis[p[i]] = 1;
        std::vector<int>pre(n + 1);
        for(int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1];
            if(vis[i]) pre[i]++;
        }
        for(int i = 1; i <= m; ++i){
            int &l = a[i].first, &r = a[i].second;
            if(pre[r] - pre[l - 1] > (r - l + 1) / 2) return true;
        }
        return false;
    };
    int l(1), r(q);
    int ans(-1);
    while(l <= r){
        int mid(l + r >> 1);
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
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
