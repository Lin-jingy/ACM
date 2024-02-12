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
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

void solve(){
    int n, s;
    std::cin >> n >> s;
    std::vector<int>a(n);
    for(size_t i(0); i < n; ++i) std::cin >> a[i];
    auto check = [&](int x){
        __int128 sum(0);
        for(auto i:a) sum += (i + x) * (i + x);
        if(sum > s) return false;
        else return true;
    };
    int l(1), r(sqrt(s));
    int ans;
    while(l <= r){
        int mid(l + r >> 1);
        if(check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    std::cout << ans / 2 << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
