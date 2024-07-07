#include <bits/stdc++.h>


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long n, p, k;
    std::cin >> n >> p >> k;
    std::cout << p * k % n;

    return 0;
}