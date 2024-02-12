#include <bits/stdc++.h>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int ans = 0;
    if (a == 150)
        ans += 1;
    else if (a == 200)
        ans += 2;
    switch (b) {
    case 34:
    case 36:
    case 38:
    case 40:
        ans += 1;
        break;
    case 45:
        ans += 2;
        break;
    }
    switch (c) {
    case 34:
    case 36:
    case 38:
    case 40:
        ans += 1;
        break;
    case 45:
        ans += 2;
        break;
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
