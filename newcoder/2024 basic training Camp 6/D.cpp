#include <bits/stdc++.h>


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    double p;
    std::cin >> p;
    std::cout << p * p * p * (1 - p) * (1 - p) + p * p * (1 - p) * (1 - p) * (1 - p);

    return 0;
}