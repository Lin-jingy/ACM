#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int, std::greater<>> mp;
    for (int i = 0, x; i < n; ++i) std::cin >> x, mp[x]++;
    for (auto [i, j] : mp) {
        if (j % 2 == 1) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}