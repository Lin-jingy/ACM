#include <bits/stdc++.h>


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, l, r;
    std::cin >> n >> l >> r;
    for(int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if(x <= l) std::cout << l << ' ';
        else if(x >= r) std::cout << r << ' ';
        else std::cout << x << ' ';
    }

    return 0;
}
