#include <bits/stdc++.h>

#define LOCAL 0
#if LOCAL
#define dbg(x...)                  \
    do {                           \
        std::cout << #x << " -> "; \
        err(x);                    \
    } while (0)

void err() {
    std::cout << std::endl
              << std::endl;
}

template <class T, class... Ts>
void err(T arg, Ts... args) {
    std::cout << std::fixed << std::setprecision(10) << arg << ' ';
    err(args...);
}
#else
#define dbg(...)
#endif

using PII = std::pair<int, int>;
using i128 = __int128;
#define All(x) x.begin(), x.end()
#define eb(x) emplace_back(x)
using vec = std::vector<int>;
void solve();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

int a[50][50];
int rx[] = {0, 1, 0, -1};
int ry[] = {1, 0, -1, 0};

void solve() {
    int n;
    std::cin >> n;
    int p = 0;
    for (int x = 1, y = 1, f = 1; f < n * n; ++f) {
        a[x][y] = f;
        int xx = x + rx[p], yy = y + ry[p];
        if (xx < 1 or xx > n or yy < 1 or yy > n or a[xx][yy] != 0) p = (p + 1) % 4;
        x = x + rx[p], y = y + ry[p];
    }
    //a[n / 2 + 1][n / 2 + 1] = 'T';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == n / 2 + 1 and j == n / 2 + 1) std::cout << "T ";
            else
                std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }
}