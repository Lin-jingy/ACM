#include<bits/stdc++.h>

#define int long long

void solve() {
    int x, k;
    std::cin >> x >> k;
    
    auto fact = [&](int mid) ->int {
        int sum = 0;
        while(mid) {
            sum += mid % 10;
            mid /= 10;
        }
        return sum;
    };

    for(int i = x; ; ++i) {
        if(fact(i) % k == 0) {
            std::cout << i << '\n';
            return ;
        }
    }

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