#include <bits/stdc++.h>

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    std::swap(a, b);
    std::vector dp(b.size() + 1, std::vector<int>(a.size() + 1, 0));
    for(int i = 1; i < b.size(); i++) {
        for(int j = 1; j < a.size(); j++) {
            if(b[i] == a[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    std::cout << a.size() + b.size() - 2 - dp[b.size() - 1][a.size() - 1] << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}