#include<bits/stdc++.h>

void solve() {
    int n;
    double v, u;
    std::cin >> n >> v >> u;
    std::vector<double> c(n + 1), d(n + 1);

    for(int i = 1; i <= n; ++i) std::cin >> c[i];
    for(int i = 1; i <= n; ++i) std::cin >> d[i];

    double time = 0;
    double dis = n * u;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            double itv = c[i] - (j - 1) * d[i];
            time += dis / (itv - v);
        }
    }

    printf("%.3lf", time / n);

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