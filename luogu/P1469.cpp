#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, x, ans = 0;
    std::cin >> n;
    while(n--) {
        std::cin >> x;
        ans ^= x;
    }
    std::cout << ans;
    return 0;
}
