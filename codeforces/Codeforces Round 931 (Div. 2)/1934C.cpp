#include <bits/stdc++.h>

#define int long long 

int ask(int a, int b) {
    std::cout << std::format("? {} {}", a, b) << std::endl;
    int x;
    std::cin >> x;
    return x;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::mt19937_64 R(time(0));
    int x = R() % n;
    int y = R() % n;
    int a1 = ask(x, y);
    int a2 = ask(x + 1, y);
    int x2 = (a2 - a1 + 1) / 2;
    int x1 = 1 + x2;
    int y1 = a2 - x2;
    std::cout << std::format("! {} {}", x + x1, y + y1) << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}