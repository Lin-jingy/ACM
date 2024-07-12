#include <bits/stdc++.h>

#define int long long
using Pii = std::pair<int, int>;

int n, v0, v1, v2;
std::vector<Pii> a;
int mx = 0;

bool check(int mid) {
    
} 

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> v0 >> v1 >> v2;
    a.assign(n, {});
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].first >> a[i].second;
        mx = std::max(mx, a[i].second);
    }

    double l = 0, r = 1e18;
    int T = 70;
    while(T--) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }

    return 0;
}