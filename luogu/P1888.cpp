#include <bits/stdc++.h>


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::array<int, 3> a;
    std::cin >> a[0] >> a[1] >> a[2];
    std::ranges::sort(a);
    int k = std::__gcd(a[0], a[2]);
    std::cout << a[0] / k << "/" << a[2] / k;

    return 0;
}