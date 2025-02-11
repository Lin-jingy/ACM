#include <bits/stdc++.h>

constexpr int N = 5001;
int a[N + 1][N + 1], pre[N + 1][N + 1];

int main() {
    int n, r;
    std::cin >> n >> r;
    for (int i = 1; i <= n; ++i) {
        int x, y, v;
        std::cin >> x >> y >> v;
        ++x, ++y;
        a[x][y] = v;
    }
    for (int i = 1; i <= N; ++i) {
        int add = 0;
        for (int j = 1; j <= N; ++j) {
            add += a[i][j];
            pre[i][j] = pre[i - 1][j] + add;
        }
    }

    auto get = [&](int x1, int y1, int x2, int y2) -> int {
        return pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] +
               pre[x1 - 1][y1 - 1];
    };

    int ans = 0;
    for (int i = 1; i <= N - r + 1; ++i) {
        for (int j = 1; j <= N - r + 1; ++j) {
            ans = std::max(ans, get(i, j, i + r - 1, j + r - 1));
        }
    }
    std::cout << ans << '\n';
}