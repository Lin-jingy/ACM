#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] % 2 == 0)
            a[i] = 0;
        else
            a[i] = 1;
    }
    int ct0 = std::count(a.begin(), a.end(), 0);
    int ct1 = n - ct0;
    if (ct0 == n or ct1 == n) {
        if (n % 2 == 0) {
            std::cout << "zn\n";
        } else {
            std::cout << "qcjj\n";
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == a[(i + 1) % n]) {
            goto A;
        }
    }
    std::cout << "zn\n";
    return;
A:;
    if (abs(ct1 - ct0) % 2 == 0) {
        std::cout << "zn\n";
    } else {
        std::cout << "qcjj\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
