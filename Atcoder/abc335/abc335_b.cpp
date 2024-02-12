#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i <= 21; ++i) {
        for (int j = 0; j <= 21; ++j) {
            for (int k = 0; k <= 21; ++k) {
                if (i + j + k <= n) {
                    std::cout << i << ' ' << j << ' ' << k << '\n';
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
