#include<bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, A, cf, cm, m;
    std::cin >> n >> A >> cf >> cm >> m;
    std::vector<int> a(n);
    int min = INT_MAX, max = 0;
    for(auto &i:a) std::cin >> i, min = std::min(min, i);
    std::vector<int> ra(a), pre(n);
    std::sort(ra.begin(), ra.end());
    pre[0] = ra[0];
    for(int i = 1; i < n; ++i) pre[i] = pre[i - 1] + ra[i];
    int rm = m, ans = 0;
    auto check = [&](int x) -> bool {
        int num = std::upper_bound(ra.begin(), ra.end(), x) - ra.begin();
        int sum = x * num - pre[num - 1];
        if(rm < sum) return false;
        else return true;
    };
    while(ra.back() == A) max++, ra.pop_back();
    for(int i = max; i <= n; ++i) {
        if(rm <= 0) break;
        int l = 0, r = A;
        int mx = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            if(check(mid)) l = mid + 1, mx = mid;
            else r = mid - 1;
        }
        if(cf * i + cm * mx > ans) ans = cf * i + cm * mx, min = mx, max = i;
        if(!ra.empty()) {
            rm -= A - ra.back();
            ra.pop_back();
        }
        
    }
    ra = a;
    ans = std::max(ans, cf * max + cm * min);
    std::sort(ra.begin(), ra.end());
    int sum = max;
    while(max --> 0) ra.pop_back();
    max = ra.back();
    std::cout << ans << '\n';
    for(auto i:a) {
        if(i > max and sum) std::cout << A << ' ', --sum;
        else std::cout << std::max(min, i) << ' ';
    }
    return 0;
}