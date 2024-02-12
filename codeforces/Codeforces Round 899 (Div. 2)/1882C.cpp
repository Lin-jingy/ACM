#include<bits/stdc++.h>
#include<array>

#define int long long

void solve() {
    int n;
    std::cin >> n;

    std::array<int, 3> a;
    int sum = 0;

    for(int i = 1, x; i <= n; ++i) {
        std::cin >> x;
        if(i <= 2) a[i] = x;
        if(x > 0) sum += x;
    }
    if(n == 1) {
        std::cout << (a[1] > 0?a[1]:0) << '\n';
        return ;
    }

    if(a[1] >= 0) std::cout << sum << '\n';
    else std::cout << (a[2] < 0?sum:(a[1]+a[2]>=0?sum + a[1]:sum - a[2])) << '\n';

    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}