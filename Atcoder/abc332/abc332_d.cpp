#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::vector<std::vector<int>> b(n, std::vector<int>(m));
    std::vector<int> xa(n);
    std::vector<int> xb(m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> a[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> b[i][j];

    for (int i = 1; i <= n; ++i)
        xa[i] = xb[i] = i;
    int ans = INT_MAX;
    int numx = 1, numy = 1;
    for (int i = 1; i <= n; ++i)
        numx *= i;
    for (int i = 1; i <= m; ++i)
        numy *= i;

    auto get = [&]() -> void {
        int k = 0;
        std::vector<int> xxa = xa;
        std::vector<int> xxb = xb;
        for (int i = n - 1; i >= 0; --i)
            for (int j = 0; j < i; ++j)
                if (xxa[j] > xxa[j + 1])
                    std::swap(xxa[j], xxa[j + 1]), ++k;
        for (int i = m - 1; i >= 0; --i)
            for (int j = 0; j < i; ++j)
                if (xxb[j] > xxb[j + 1])
                    std::swap(xxb[j], xxb[j + 1]), ++k;
        ans = std::min(ans, k);
    };
    auto check = [&]() -> bool {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[xa[i]][xb[j]] != b[i][j])
                    return false;
            }
        }
        return true;
    };
    for (int i = 1; i <= numx; ++i) {
        for (int j = 1; j <= numy; ++j) {
            if (check())
                get();
            std::next_permutation(xb.begin(), xb.end());
        }
        std::next_permutation(xa.begin(), xa.end());
    }
    if (ans != INT_MAX)
        std::cout << ans << '\n';
    else
        std::cout << -1 << '\n';
    return 0;
}
