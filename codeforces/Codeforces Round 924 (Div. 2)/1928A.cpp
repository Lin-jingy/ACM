#include <iostream>

void solve() {
    int a, b;
    std::cin >> a >> b;
    if ((b % 2 == 0 and b != a * 2) or (a % 2 == 0 and a != b * 2)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}