#include <bits/stdc++.h>

bool a[500][500];

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    int ans = 0;
    while (k--) {
        int x, y;
        std::cin >> x >> y;
        a[x][y] = 1;
        ans += 4;
        if (a[x - 1][y]) --ans;
        if (a[x][y - 1]) --ans;
        if (a[x + 1][y]) --ans;
        if (a[x][y + 1]) --ans;
    }
    std::cout << ans << '\n';
    return 0;
}
