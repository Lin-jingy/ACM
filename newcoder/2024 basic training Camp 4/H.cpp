#include <bits/stdc++.h>

std::string s[505];
int x[505][505], y[505][505], z[505][505], ur[505][505], ul[505][505];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        std::cin >> s[i];
        s[i] = ' ' + s[i];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            x[i][j] = x[i][j - 1] + (s[i][j] == '*');
            ur[i][j] = ur[i - 1][j + 1] + x[i][j] - x[i][j - 1];
            ul[i][j] = ul[i - 1][j - 1] + x[i][j] - x[i][j - 1];
        }
    }
    for(int i = n; i >= 1; --i) {
        for(int j = m; j >= 1; --j) {
            y[i][j] = y[i + 1][j - 1] + (s[i][j] == '*');
            z[i][j] = z[i + 1][j + 1] + (s[i][j] == '*');
        }
    }

    int ans = 0;

    auto check = [&](int px, int py, int k) -> bool {
        if(px - k >= 1 and py + 2 * k <= m) {
            
        }
    };
    auto add = [&](int px, int py) -> int {
        int sum = 0;
        for(int i = 1; ; ++i) {
            if(check(px + i, py - i) and check(px + i, py + i)) {
                if(x[px + i][py + i] - x[px + i][py - i - 1] == 2 * i + 1 and
                y[px + i][py - i] - y[px][py] == i and z[px + i][py + i] - z[px][py] == i)++sum;
            }else {
                break;
            }
        }
        return sum;
    };

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s[i][j] == '*') ans += add(i, j);
        }
    }
    std::cout << ans << '\n';

    return 0;
}