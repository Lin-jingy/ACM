#include<bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    if(n <= 2) std::cout << 1 << '\n';
    else {
        int ans = (n - 2 + k - 1) / k;
        std::cout << ans + 1 << '\n';
    }


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