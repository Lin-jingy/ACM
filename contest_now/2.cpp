#include <bits/stdc++.h>

#define int long long 

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 10);
    while(k--) {
        int l, r;
        std::cin >> l >> r;
        a[l]++;
        a[r + 1]--; 
    }

    for(int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }

    std::sort(a.begin() + 1, a.begin() + n + 1);
    std::cout << a[(n + 1) / 2] << '\n';

    return 0;
}