#include <bits/stdc++.h>

void solve() {
    int n, m, d;
    std::cin >> n >> m >> d;
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    long long ans = 0;
    long long sum = 0;
    for(long long i = 1, x; i <= n; ++i) {
        std::cin >> x;
        if(x > 0) q.push(x), sum += x;
        while(q.size() > m) sum -= q.top(), q.pop();
        ans = std::max(ans, sum - d * i);
    }
    
    std::cout << ans << '\n';

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
