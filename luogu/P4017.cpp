#include <bits/stdc++.h>

#define int long long
constexpr int mod = 80112002;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n + 1);
    std::vector<int> du(n + 1), d(n + 1);
    while(m--) {
        int a, b;
        std::cin >> a >> b;
        v[b].push_back(a);
        du[a]++; d[b]++;
    }

    std::queue<int> q;
    std::vector<int> dp(n + 1);
    for(int i = 1; i <= n; ++i) if(du[i] == 0) q.push(i), dp[i] = 1;
    std::vector<int> list;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        list.push_back(p);
        for(auto i:v[p]) {
            du[i]--;
            if(du[i] == 0) q.push(i);
        }
    }

    for(auto i:list) {
        for(auto j:v[i]) {
            dp[j] = (dp[j] + dp[i]) % mod;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) if(d[i] == 0) ans = (ans + dp[i]) % mod;

    std::cout << ans << '\n';    

    return 0;
}