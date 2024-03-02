#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    if(n % 2 == 1) std::cout << "-1\n";
    else {
        int p[26];
        memset(p, 0, sizeof(p));
        for(auto i:s) p[i - 'a'] ++;
        for(auto i:p) if(i > n / 2) return std::cout << "-1\n", void();
        int ans = 0;
        s = ' ' + s;
        memset(p, 0, sizeof(p));
        for(int i = 1; i <= n / 2; ++i) {
            if(s[i] == s[n - i + 1]) p[s[i] - 'a']++, ans ++;
        }
        int mx = 0;
        for(int i = 0; i < 26; ++i) mx = std::max(mx, p[i]);
        std::cout << std::max((ans + 1) / 2, mx) << '\n';
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