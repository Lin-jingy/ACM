#include <bits/stdc++.h>

#define int long long

void solve() {
    std::string s;
    std::cin >> s;
    int a = 0, b = 0;
    for (int i = 1; i < s.size(); ++i) {
        if(s[0] == '0' or s[i] == '0')
            continue;
        a = b = 0;
        for (int j = 0; j < i; ++j)
            a = a * 10 + s[j] - '0';
        for (int j = i; j < s.size(); ++j)
            b = b * 10 + s[j] - '0';
        if(b > a) {
            std::cout << a << ' ' << b << '\n';
            return;
        }
    }
    std::cout << -1 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}
