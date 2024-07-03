#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    T y = 1, len = 1;
    for (; y <= x / 10; y *= 10) ++len;
    for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}

int t, n;

int main() {
    for (read(t); t; --t) {
        read(n);
        if (n & 1) write((n + 1) * (2 * n * n + 3 * n - 1) / 8);//奇数 
        else write(n * (n + 2) * (2 * n + 1) / 8);//偶数 
        putchar('\n');
    }
    return 0;
}