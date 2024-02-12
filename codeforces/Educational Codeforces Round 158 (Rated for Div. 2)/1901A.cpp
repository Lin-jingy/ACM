#include<bits/stdc++.h>

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for(auto &i:a) std::cin >> i;
    int ans = 0, last = 0;
    for(auto i:a) {
        ans = std::max(ans, i - last);
        last = i;
    }
    ans = std::max(ans, 2 * (x - a.back()));
    last = x;
    for(int i = n - 1; i >= 0; --i) {
        ans = std::max(ans, last - a[i]);
        last = a[i];
    }
    std::cout << ans << '\n';

    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}