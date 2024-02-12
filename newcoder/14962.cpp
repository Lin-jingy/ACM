#include<bits/stdc++.h>

void solve() {
    int n, l, r, m, L, R;
    std::cin >> n >> l >> r >> m >> L >> R;

    if(l > R or m == 0) {
        std::cout << 100.00000 << '\n';
        return ;
    }
    if(L > R or n == 0) {
        std::cout << 0.00000 << '\n';
        return ;
    }

    int sum1 = 0;
    int sum2 = 0;
    for(int i = l; i <= r; ++i) {
        for(int j = L; j <= R; ++j) {
            if(i > j) ++sum1;
            if(i < j) ++sum2;
        }
    }
    //std::cout << sum << '\n';
    double k = 1.0 * sum1 / (sum1 + sum2); 
    printf("%.5lf", (n * k) / (n * k + m * (1 - k)));

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