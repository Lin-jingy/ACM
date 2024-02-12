#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define int long long

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> mp;
    while (n--) {
        int a, b;
        std::cin >> a >> b;
        mp[a] += b;
    }
    int ans = m;
    int k = 0;
    for (auto i : mp) {
        k += i.second;
        if (i.first - k <= m) ans = std::max(ans, i.first + m - (i.first - k));
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
