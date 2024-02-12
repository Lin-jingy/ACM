#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string mid[n], a[n + 1];
    for(int i = 0; i < n; ++i) std::cin >> mid[i];
    for(int i = 1; i <= n; ++i) {
        a[i] += ' ';
        a[i] += mid[i - 1];
    }
    int ans = 0;
    std::array<char, 4> s;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            s[0] = a[i][j];
            s[1] = a[j][n - i + 1];
            s[2] = a[n - i + 1][n - j + 1];
            s[3] = a[n - j + 1][n - (n - i + 1) + 1];
            int mx = s[0] - 'a';
            for(int i = 1; i < 4; ++i) mx = std::max(mx, s[i] - 'a');
            for(int i = 0; i < 4; ++i) ans += mx - (s[i] - 'a');
        }
    }
    std::cout << ans / 4 << '\n';


}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
