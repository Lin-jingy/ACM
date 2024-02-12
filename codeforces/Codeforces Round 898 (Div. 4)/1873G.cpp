#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    int ans = 0;
    for (int i = 0, j = -1; i <= s.size(); i++) {
        if (i == s.size() or s[i] == 'C') {
            int min = s.size();
            for (int x = j + 1, y = j; x <= i; x++) {
                if (x < i && s[x] == 'A') ans++;
                else min = std::min(min, x - y - 1), y = x;
            }
            ans -= min;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}