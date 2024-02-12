#include<bits/stdc++.h>

const int mod = 1e9 + 7;
int n;

void solve() {
    std::array<std::array<long long, 2>, 2> a;
    
    std::cin >> a[0][0] >> a[0][1];

    for(int i = 2; i <= n; ++i) {
        int x, y;
        std::cin >> x >> y;
        a[1][0] = (a[0][0] + a[0][1]) * x % mod;
        a[1][1] = (a[0][0] + a[0][1]) * y % mod;
        a[0][0] = a[1][0];
        a[0][1] = a[1][1];
    }

    std::cout << (a[1][0] + a[1][1]) % mod << '\n';

    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    while(std::cin >> n) solve();
    return 0;
}