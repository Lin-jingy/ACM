#include<bits/stdc++.h>

void solve() {
    int n, mn = 10;
    std::cin >> n;
    std::vector<int>a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i], mn = std::min(mn, a[i]);
    int ans = 1;
    for(int i = 0; i < n; ++i) if(a[i] == mn) {
        a[i]++;
        break;
    }
    for(auto i:a) ans *= i;
    std::cout << ans << '\n';

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}