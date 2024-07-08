#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("1.out", "w", stdout);
    int n;
    std::cin >> n;

    if(n % 2 == 0) {
        std::cout << 6 << '\n';
        for(int i = 1; i <= n; ++i) std::cout << i << ' ';
        std::cout << '\n';
        for(int i = n + 1; i <= n + n; ++i) std::cout << i << ' ';
        std::cout << '\n';

        int k = n / 2;
        for(int i = 1; i <= k; ++i) std::cout << i << ' ';
        for(int i = n + 1; i <= n + k; ++i) std::cout << i << ' ';
        std::cout << '\n';

        for(int i = k + 1; i <= n; ++i) std::cout << i << ' ';
        for(int i = n + 1; i <= n + k; ++i) std::cout << i << ' ';
        std::cout << '\n';

        for(int i = 1; i <= k; ++i) std::cout << i << ' ';
        for(int i = n + k + 1; i <= n + n; ++i) std::cout << i << ' ';
        std::cout << '\n';

        for(int i = k + 1; i <= n; ++i) std::cout << i << ' ';
        for(int i = n + k + 1; i <= n + n; ++i) std::cout << i << ' ';
        std::cout << '\n';
    } else {
        std::cout << 6 << '\n';

        for(int i = n + 1; i <= n + n; ++i) std::cout << i << ' ';
        std::cout << '\n';
        
        int k1 = n / 2;
        int k2 = n - k1;
        for(int i = 1; i <= k2; ++i) std::cout << i << ' ';
        for(int i = n + n - k1 - k1 + 1; i < n + n - k1 + 1; ++i) std::cout << i << ' ';
        std::cout << '\n';

        for(int i = k2; i <= k2 + k2 - 1; ++i) std::cout << i << ' ';
        for(int i = n + n - k1 + 1; i <= n + n; ++i) std::cout << i << ' ';   
        std::cout << '\n';

        for(int i = 1; i <= k1; ++i) std::cout << i << ' ';
        std::cout << k2 + 1 << ' ';
        for(int i = n + n - k1 + 1; i <= n + n; ++i) std::cout << i << ' '; 
        std::cout << '\n';

        for(int i = 1; i <= k2; ++i) std::cout << i << ' ';
        for(int i = k2 + k2 - k1 + 1; i <= k2 + k2; ++i) std::cout << i << ' ';
        std::cout << '\n';

        for(int i = k2 + 1; i <= k2 + k1; ++i) std::cout << i << ' ';
        for(int i = k2 + k2; i <= k2 + k2 + k1; ++i) std::cout << i << ' ';
        std::cout << '\n';


    }

    return 0;
}