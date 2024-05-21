#include <bits/stdc++.h>

int f[1000005], a[1000005];
int find(int p) {
    return f[p] == p ? p : f[p] = find(f[p]);
}

void solve() {
    int n, m, p, q;
    std::cin >> n >> m >> p >> q;
    for(int i = 1; i <= n + 1; ++i) f[i] = i;
    for(int i = m; i >= 1; --i) {
        int l = (i * p + q) % n + 1, r = (i * q + p) % n + 1;
        if(l > r) std::swap(l, r);
        for(int j = find(l); j <= r; ) {
            f[j] = r + 1;
            a[j] = i;
            ++j;
            j = find(j);
        }
    }
    for(int i = 1; i <= n; ++i) std::cout << a[i] << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
