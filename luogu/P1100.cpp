#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int x;
    std::cin >> x;
    std::string a;
    while (x) {
        a += x % 2 + '0';
        x /= 2;
    }
    while (a.size() < 32) a += '0';
    std::reverse(a.begin(), a.end());
    for (int i = 0; i < 16; ++i) std::swap(a[i], a[i + 16]);
    std::cout << std::stoll(a, 0, 2);
    return 0;
}
