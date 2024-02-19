#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, sum = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i], sum += a[i];
    if(n == 1) {
        std::cout << 1 << '\n';
        return 0;
    }

    int ans = 0;
    for(int i = 1; i <= 2e5; ++i) {
        if(sum % i == 0 and sum / i >= n) {
            // std::cout << i << ' ' ;
            ++ans;
        }
    }

    std::cout << ans << '\n';

    return 0;
}