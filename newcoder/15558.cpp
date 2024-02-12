#include<bits/stdc++.h>

#define int long long

void solve() {
    int a, b, k;
    std::cin >> a >> b >> k;
    printf("%.3lf\n", b / (a + b));
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