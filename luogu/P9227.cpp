#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int x = 0;
    for(int &i:a) std::cin >> i, x ^= i;
    if(n % 2 == 0 and k % 2 == 0) {
        for(auto i:a) std::cout << i << ' ';
        std::cout << '\n';
    } else {
        for(int i = 0; i < n; ++i) std::cout << (x ^ a[i]) << ' ';
        std::cout << '\n';
        
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