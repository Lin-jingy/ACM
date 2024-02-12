#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> p(35);
    for (int i = 1; i <= n; ++i) {
        int op, x;
        std::cin >> op >> x;
        if(op == 1) {
            p[x]++;
        }else {
            for (int i = 29; i >= 0; --i) {
                int k = 1LL << i;
                int num = x / k;
                num = std::min(num, p[i]);
                x -= num * k;
            }
            if(x != 0)
                std::cout << "NO\n";
            else
                std::cout << "YES\n";
        }
    }

        return 0;
}
