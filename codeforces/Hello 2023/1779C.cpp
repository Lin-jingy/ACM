#include<bits/stdc++.h>

#define int long long 

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    int ans = 0, sum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for(int i = 1; i <= m; ++i) {
        q.push(a[i]);
        if(sum + a[i] < 0) sum -= 2 * a[i], q.pop(), ++ans;
        sum += a[i];
    }
    std::cout << ans << '\n';

}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}