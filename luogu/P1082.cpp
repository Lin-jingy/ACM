#include <algorithm>
#include <iostream>

static int Exgcd(int a, int b, int &x, int &y) {
    // 求 $ax+by=\gcd(a,b)$ 的一组可行解
    // 函数返回值为gcd(a, b)
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = Exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    int x, y;
    Exgcd(a, b, x, y);
    std::cout << (x + b) % b << '\n';
    return 0;
}