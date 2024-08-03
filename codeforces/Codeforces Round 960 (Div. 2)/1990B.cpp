#include <bits/stdc++.h>

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> a(n + 1, 1);
    if (x >= y) {
        std::fill(a.begin() + x + 1, a.end(), -1);
        std::fill(a.begin(), a.begin() + y, -1);
    } else {
        
    }
    for (int i = 1; i <= n; ++i) std::cout << a[i] << ' ';
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}