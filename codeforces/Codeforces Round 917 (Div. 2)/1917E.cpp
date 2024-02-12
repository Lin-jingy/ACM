#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector v(n / 2, std::vector<std::array<std::array<int, 2>, 2>>(n / 2));
    std::array<std::array<int, 2>, 2> a = {0, 0, 0, 0};
    if (k % 4 == 0) {
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                a = {0, 0, 0, 0};
                if (k) a[0][0] = 1, --k;
                if (k) a[0][1] = 1, --k;
                if (k) a[1][0] = 1, --k;
                if (k) a[1][1] = 1, --k;
                v[i][j] = a;
            }
        }
    } else if (k % 4 == 2 and k >= 6 and k <= n * n - 10) {
        k -= 6;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                if (i <= 1 and j <= 1) continue;
                a = {0, 0, 0, 0};
                if (k) a[0][0] = 1, --k;
                if (k) a[0][1] = 1, --k;
                if (k) a[1][0] = 1, --k;
                if (k) a[1][1] = 1, --k;
                v[i][j] = a;
            }
        }
        v[0][0] = {1, 1, 1, 0};
        v[0][1] = {0, 0, 1, 0};
        v[1][0] = {0, 1, 0, 0};
        v[1][1] = {1, 0, 0, 0};
    } else if (k == n * n - 6) {
        k -= 10;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                if (i <= 1 and j <= 1) continue;
                a = {0, 0, 0, 0};
                if (k) a[0][0] = 1, --k;
                if (k) a[0][1] = 1, --k;
                if (k) a[1][0] = 1, --k;
                if (k) a[1][1] = 1, --k;
                v[i][j] = a;
            }
        }
        v[0][0] = {1, 1, 1, 0};
        v[0][1] = {0, 0, 1, 0};
        v[1][0] = {1, 1, 1, 0};
        v[1][1] = {1, 1, 0, 1};
    } else if (k == 2 and n == 2) {
        v[0][0] = {1, 0, 0, 1};
    } else {
        std::cout << "No\n";
        return;
    }
    std::cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << v[i / 2][j / 2][i % 2][j % 2] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
