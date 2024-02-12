#include <bits/stdc++.h>

struct node {
    int a, b, p;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<node> ask(n);
    std::vector<std::array<int, 4>> v;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k) {
                v.push_back({0, i, j, k});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> ask[i].a >> ask[i].b >> ask[i].p;
    }
    for (auto i : v) {
        for (auto [a, b, p] : ask) {
            if (p == 1 and i[a] >= i[b]) {
                goto A;
            } else if (p == 0 and i[a] < i[b]) {
                goto A;
            }
        }
        std::cout << "Yes\n";
        return;
    A:;
    }
    std::cout << "No\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
