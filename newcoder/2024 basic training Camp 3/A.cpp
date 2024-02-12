#include <bits/stdc++.h>

char ch(char x) {
    if (x >= 'A' and x <= 'Z') return x - 'A' + 'a';
    else
        return x;
}

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    if (ch(a.front()) == ch(b.front())) {
        std::cout << "Yes\n";
    }else {
        std::cout << "No\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
