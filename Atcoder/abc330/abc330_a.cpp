#include <bits/stdc++.h>


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, k;
    std::cin >> n >> k;
    int num = 0;
    while(n--) {
        int x;
        std::cin >> x;
        num += x >= k;
    }
    std::cout << num << '\n';
    return 0;
}
