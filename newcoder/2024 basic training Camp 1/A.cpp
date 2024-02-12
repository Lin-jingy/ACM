#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'd') {
            for (; i < n; ++i) {
                if (s[i] == 'f') {
                    for (; i < n; ++i) {
                        if (s[i] == 's') {
                            a = 1;
                            goto A;
                        }
                    }
                    goto A;
                }
            }
            goto A;
        }
    }
A:;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'D') {
            for (; i < n; ++i) {
                if (s[i] == 'F') {
                    for (; i < n; ++i) {
                        if (s[i] == 'S') {
                            b = 1;
                            goto B;
                        }
                    }
                    goto B;
                }
            }
            goto B;
        }
    }
B:;
    std::cout << b << ' ' << a << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
