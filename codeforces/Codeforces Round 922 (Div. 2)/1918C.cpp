#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        long long a, b, r;
        std::cin >> a >> b >> r;
        bool flag = 0;
        for (int i = 63; i >= 0; --i) {
            int ra = (a >> i) & 1;
            int rb = (b >> i) & 1;
            if (ra != rb) {
                if (!flag) {
                    flag = 1;
                    if (ra < rb) std::swap(a, b);
                } else if (ra == 1 and r >= (1LL << i)) {
                    r -= (1LL << i);
                    a ^= (1LL << i);
                    b ^= (1LL << i);
                }
            }
        }
        std::cout << a - b << '\n';
    }
}