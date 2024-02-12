#include <bits/stdc++.h>

#define int long long

static int Exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = Exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int X, Y, m, n, L;
    std::cin >> X >> Y >> m >> n >> L;
    if (X == Y) {
        std::cout << 0 << '\n';
        return 0;
    }
    if (n < m) std::swap(X, Y), std::swap(n, m);
    int x, y;
    Exgcd(L, n - m, x, y);
    if ((X - Y) % std::gcd(L, n - m) != 0 or n == m) {
        std::cout << "Impossible\n";
    } else {
        int g = std::gcd(L, n - m);
        std::cout << (y * ((X - Y) / g) % (L / g) + (L / g)) % (L / g) << '\n';
    }

    return 0;
}
