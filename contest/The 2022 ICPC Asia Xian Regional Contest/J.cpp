#include<bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<int> q;
    for(int i = 0, x; i < n; ++i) {
        std::cin >> x;
        if(x > 0) q.push(x);
    }
    int ans = 0;
    if(q.size() >= 2) {
        ans += q.top(); q.pop();
        ans += q.top(); q.pop();
    }else if(q.size() == 1) {
        ans += q.top();
    }
    std::cout << ans << '\n';

    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}