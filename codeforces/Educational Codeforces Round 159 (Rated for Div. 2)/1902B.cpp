#include <bits/stdc++.h>

#define int long long
using i128 = __int128;

void solve() {
    int n, p, l, t;
    std::cin >> n >> p >> l >> t;
    i128 P = p;
    int k = (n - 1) / 7 + 1;
    int L = 0, R = n;
    int ans = n;
    auto check = [&](int x) {
        i128 sum = 0;
        sum += (i128)x * l;
        sum += (i128)t * std::min(2 * x, k);
        if(sum >= P) return true;
        else return false;
    };
    while(L <= R) {
        int mid = L + R >> 1;
        if(check(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    std::cout << n - ans << '\n';


}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
