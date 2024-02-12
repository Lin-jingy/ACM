#include <bits/stdc++.h>

#define int long long

int p[9][10];

int ch(int x) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1, x; i <= n; ++i) {
        std::cin >> x;
        a[i] = x;
        int c = ch(x) % 9;
        p[c][x % 10]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            int x = a[i];
            int k = (9 - ch(a[i]) % 9) % 9;
            if (x < 10) x = j * 10 + x;
            if (x % 4 == 0) {
                if (k == 0 and a[i] % 10 == j) {
                    ans += p[k][j] - 1;
                } else {
                    ans += p[k][j];
                }
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}

/*
36
72
108
144
180
216
252
288
324
360
*/