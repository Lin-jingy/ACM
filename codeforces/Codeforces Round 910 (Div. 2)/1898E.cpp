#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string S, T;
    std::cin >> S >> T;
    std::queue<int> pos[26];
    for(int i = 0; i < n; ++i) pos[S[i] - 'a'].push(i);
    int P[26];
    memset(P, 0, sizeof(P));
    for(auto i:T) {
        int k = i - 'a';
        if(pos[k].empty()) return std::cout << "NO\n", void();
        P[k] = pos[k].front();
        for(int j = 0; j <= k; ++j) while(not pos[j].empty() and pos[j].front() <= P[k]) pos[j].pop();
    }
    std::cout << "YES\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}