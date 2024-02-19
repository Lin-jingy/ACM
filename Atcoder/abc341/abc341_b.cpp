#include <iostream>
#include <vector>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), s(n), t(n);
    for(int &i:a) std::cin >> i;
    for(int i = 0; i < n; ++i) std::cin >> s[i] >> t[i];
    for(int i = 0; i < n - 1; ++i) {
        a[i + 1] += a[i] / s[i] * t[i];
    }
    std::cout << a[n - 1] << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}