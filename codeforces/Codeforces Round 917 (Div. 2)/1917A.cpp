#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i : a) std::cin >> i;
    int k = std::count(a.begin(), a.end(), 0);
    int kk = 0;
    for (int i = 0; i < n; ++i) if (a[i] < 0) ++kk;
    if (kk % 2 == 1) {
        std::cout << "0\n";
        return;
    }
    if (k == 0) {
        std::cout << "1\n1 0\n";
        return;
    }
    std::cout << "0\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
