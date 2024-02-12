#include<bits/stdc++.h>

void solve() {
    int n, x;
    std::cin >> n >> x;
    int sum = 0;
    while(n--) {
        int k;
        std::cin >> k;
        if(k <= x) sum += k;
    }
    std::cout << sum << '\n';

    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}