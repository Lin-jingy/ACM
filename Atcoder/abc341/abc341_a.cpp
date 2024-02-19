#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    std::string s = "01";
    std::string ans = "1";
    while(n--) ans += s;
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}