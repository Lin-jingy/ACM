#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::mt19937 rnd(time(0));
    int n;
    std::cin >> n;
    // double rx = 0;
    // for (int i = 0; i < n; ++i) {
    //     int x, y, r;
    //     while (1) {
    //         x = rnd() % 201 - 100;
    //         y = rnd() % 201 - 100;
    //         r = rnd() % 100 + 1;
    //         if (x + r <= 100 and x - r >= -100 and y + r <= 100 and y - r >= -100) break;
    //     }
    //     if (x > 0) rx += x;
    // }
    // std::cout << rx / n;
    double rx = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        std::cin >> x >> y >> r;
        if (x > 0) rx += x;
    }
    if (rx / n >= 24)
        std::cout << "bit-noob";
    else
        std::cout << "buaa-noob";

    return 0;
}
