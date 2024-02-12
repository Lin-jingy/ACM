#include<bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    if(m == 1) std::cout << 0 << '\n';
    else if(m == 2) std::cout << 2 << '\n';
    else std::cout << std::min(n + 1, m) << '\n';
    for (int i = 0; i < n; i++) {
        std::vector<int> a(m);
        std::iota(a.begin(), a.end(), 0);
        int flag = 0;
        for(auto &j:a) j = flag++;
        int p = std::max(1, m - i - 1);
        std::reverse(a.begin(), a.begin() + p);
        std::reverse(a.begin() + p, a.end());
        for (auto j:a) std::cout << j << ' ';
        std::cout << '\n';
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