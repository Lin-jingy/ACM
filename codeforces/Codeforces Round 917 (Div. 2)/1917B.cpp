#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ans = 0;
    std::vector<int> p(26, n);
    for (int i = 0; i < n; ++i) {
        p[s[i] - 'a'] = std::min(p[s[i] - 'a'], i);
    }
    for (int i = 0; i < 26; ++i) {
        ans += n - p[i];
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
