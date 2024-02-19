#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    int op = 0;
    for(int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        op += x - 1;
    }
    if(op % 2 == 1) std::cout << "gui";
    else std::cout << "sweet";

    return 0;
}