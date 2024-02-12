#include<bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::priority_queue<int>>v(k + 1);
    std::vector<int>p(k + 1);
    for(int i = 1, x; i <= n; ++i) {
        std::cin >> x;
        v[x].push(i - p[x]);
        p[x] = i;
    }
    for(int i = 1; i <= k; ++i) v[i].push(n + 1 - p[i]);
    for(int i = 1; i <= k; ++i) {
        int k = v[i].top();
        v[i].pop();
        v[i].push((k + 1) / 2);
    }
    int mn = INT_MAX;
    for(int i = 1; i <= k; ++i) mn = std::min(mn, v[i].top());
    std::cout << mn - 1 << '\n';
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}