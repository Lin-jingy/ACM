#include <bits/stdc++.h>

#define int long long


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];

    std::vector<int> t(n + 1);
    int p = d;
    t[0] = d;
    for(int i = 1; i <= n; ++i) {
        p = std::min(p, std::abs(p - a[i]));
        t[i] = p;
    }

    std::vector<bool> ans(n + 1);
    int mex = 1;
    for(int i = n; i >= 1; --i) {
        if(mex <= t[i - 1]) ans[i] = 1;
        if(std::abs(mex - 1 - a[i]) <= mex) mex = mex + a[i];
    }
    for(int i = 1; i <= n; ++i) std::cout << ans[i];

    return 0;
}