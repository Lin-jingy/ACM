#include <iostream>
#include <algorithm>
#include <numeric>

#define int long long
using i128 = __int128;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    i128 l = 0, r = 6e18;
    int ans;
    auto check = [&](i128 x) {
        i128 num = x / n + x / m - 2 * (x / std::lcm(n, m));
        return num >= (i128)k;
    };
    while(l <= r) {
        i128 mid = (l + r) / 2;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    std::cout << ans << '\n';
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}