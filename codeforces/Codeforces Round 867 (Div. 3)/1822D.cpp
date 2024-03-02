#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    // std::vector<int> a(n);
    // for(int i = 0; i < n; ++i) a[i] = i + 1;
    // do {
    //     int sum = 0;
    //     std::vector<bool> p(n + 1);
    //     for(auto i:a) {
    //         sum += i;
    //         p[sum % n + 1] = 1;
    //     }
    //     for(int i = 1; i <= n; ++i) if(!p[i]) goto A;
    //     for(int i = 0; i < n; ++i) std::cout << a[i] << " \n"[i == n - 1];
    //     A:;
    // } while(std::next_permutation(a.begin(), a.end()));
    if(n == 1) {
        std::cout << 1 << '\n';
    }else if(n % 2 == 0) {
        int pre = n;
        int la = n;
        std::cout << n << ' ';
        for(int i = 1; i < n; ++i) {
            std::cout << (i % 2 ? n - i : i) << ' ';
        }
        std::cout << '\n';
    }else {
        std::cout << "-1\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}