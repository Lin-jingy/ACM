#include <bits/stdc++.h>

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> d(q + 1);
    for(int i = 1; i <= q; ++i) std::cin >> d[i];
    for(int i = 1; i < n; ++i) std::cout << i << ' ' << i + 1 << '\n';
    d[0] = n - 1;
    for(int i = 1; i <= q; ++i) {
        if(d[i - 1] == d[i]) std::cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
        else std::cout << n << ' ' << d[i - 1] << ' ' << d[i] << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
