#include<bits/stdc++.h>

void solve() {
    int n, m, a, b, c;
    std::cin >> n >> m >> a >> b >> c;
    std::vector<int> p(m);
    for(int i = 0; i < m; ++i) std::cin >> p[i];
    std::sort(p.begin(), p.end());
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        
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