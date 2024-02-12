#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int ans = INT_MAX;
    for (int i = 0, d, s; i < n; i++) {
        std::cin >> d >> s;
        ans = std::min(ans, d + (s - 1) / 2);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
