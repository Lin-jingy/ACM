#include <bits/stdc++.h>

#define int long long 

void solve() {
    std::array<int, 3> a;
    for(int i = 0; i < 3; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    if(a[2] % a[0] != 0) {
        std::cout << "NO\n";
        return ;
    }
    int k = 0;
    k = a[2] / a[0] - 1;
    if(a[1] % a[0] != 0) {
        std::cout << "NO\n";
        return ;
    }
    k += a[1] / a[0] - 1;
    if(k > 3) {
        std::cout << "NO\n";
        return ;
    }
    std::cout << "YES\n";

}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
