#include <bits/stdc++.h>

int ask(int a, int b) {
    std::cout << std::format("? {} {}", a, b) << std::endl;
    int x;
    std::cin >> x;
    return x;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}