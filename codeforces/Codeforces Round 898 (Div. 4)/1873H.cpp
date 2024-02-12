#include<bits/stdc++.h>

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<std::vector<int>> r(n + 1);
    std::vector<int> d(n + 1);
    while(n--) {
        int u, v;
        std::cin >> u >> v;
        r[u].emplace_back(v);
        r[v].emplace_back(u);
        d[u]++, d[v]++;
    }
    
    
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}