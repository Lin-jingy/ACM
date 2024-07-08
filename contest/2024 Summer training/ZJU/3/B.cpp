#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    for(int i = 0; i < n; ++i) std::cin >> b[i];

    std::ranges::sort(a);
    std::ranges::sort(b);

    int num = 0;
    for(int i = 0; i < n; ++i) {
        num += std::ranges::lower_bound(b, a[i]) - b.begin();
        num -= std::ranges::lower_bound(a, b[i]) - a.begin();
    }
    printf("%.8lf", (double)num / n);
    return 0;
}