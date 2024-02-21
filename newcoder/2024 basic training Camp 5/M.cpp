#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    for(int i = 0; i < n; ++i) std::cin >> b[i];
    if(n == 1) {
        std::cout << -1 << '\n';
        return ;
    }
    if(n == 2 and a[1] == b[1] and a[2] == b[2]) {
        std::cout << -1 << '\n';
        return;
    }
    for(int i = 0; i < n; ++i) {
        if((a[i] == b[i + 1]) or (b[i] == a[i + 1])) {
            std::cout << 1 << '\n';
            return ;
        }
    }
    for(int i = 1; i < n - 1; ++i) {
        if(a[i] == b[i]) {
            std::cout << 1 << '\n';
            return ;
        }
    }
    std::cout << 2 << '\n';
}

signed main() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}