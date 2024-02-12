#include<bits/stdc++.h>

#define int long long 

void solve(){
    int t;
    std::cin >> t;
    
    std::vector<std::vector<int>>a(t + 1);

    int mn = INT_MAX, ans = 0, mn1 = INT_MAX;

    for(int i = 1; i <= t; ++i){
        int n;
        std::cin >> n;
        for(int j = 0, x; j < n; ++j) std::cin >> x, a[i].push_back(x);
        std::sort(a[i].begin(), a[i].end());
        mn = std::min(mn, a[i].front());
        mn1 = std::min(mn1, a[i][1]);
        ans += a[i][1];
    }
    
    ans -= mn1;
    ans += mn;

    std::cout << ans << '\n';

}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}