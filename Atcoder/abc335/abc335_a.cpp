#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    s.pop_back();
    std::cout << s + "4" << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while (T--) solve();
    return 0;
}
