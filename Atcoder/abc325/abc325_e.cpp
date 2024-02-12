#include <bits/stdc++.h>

#define int long long

int d[1005][1005];
int d1[1005][1005];
int d2[1005][1005];

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, a, b, c;
    std::cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> d[i][j];

    memcpy(d1, d, sizeof(d));
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d1[i][j] = std::min(d1[i][j], d1[i][k] + d1[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            d1[i][j] *= a;

    memcpy(d2, d, sizeof(d));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            d2[i][j] = d2[i][j] * b + c;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d2[i][j] = std::min(d2[i][j], d2[i][k] + d2[k][j]);
            }
        }
    }

    int ans = LONG_LONG_MAX;
    for (int i = 1; i < n; ++i) {
        ans = std::min(ans, d1[1][i] + d2[i][n]);
    }
    ans = std::min(ans, d1[1][n]);

    std::cout << ans << '\n';

    return 0;
}
