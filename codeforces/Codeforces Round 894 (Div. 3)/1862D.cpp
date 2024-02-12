#include <bits/stdc++.h>


void solve() {
    long long n;
    std::cin >> n;
    // x * (x - 1) == 2 * n
    // x * (1 + x) / 2
    __int128 l = 2, r = 1e18;
    long long ans = 0;
    while(l <= r) {
        __int128 mid = l + r >> 1;
        if(mid * (mid - 1) / 2 < n) l = mid + 1;
        else ans = (long long)mid, r = mid - 1;
    }
    if(ans * (ans - 1) / 2 == n) {
        std::cout << ans << '\n';
        return ;
    }
    --ans;
    __int128 mm = n - (ans * (ans - 1)) / 2;
    std::cout << ans + (long long)mm << '\n';
    

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
