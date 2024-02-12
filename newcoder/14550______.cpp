#include<bits/stdc++.h>

using PII = std::pair<int, int>;

void solve(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<PII>>a(n + 1);

    while(m--){
        int u, v, w;
        std::cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    auto dij = [&](int begin, int f) -> std::pair<int, int>{
        std::vector<bool>vis(n + 1);
        std::vector<long long>dis(n + 1, LONG_LONG_MAX);
        dis[begin] = 0;
        std::priority_queue<PII, std::vector<PII>, std::greater<PII>>q;
        q.push({0, begin});
        while(!q.empty()){
            int di = q.top().first, pos = q.top().second;
            q.pop();
            if(vis[pos]) continue;
            vis[pos] = 1;
            for(auto i:a[pos]){
                if(i.second + di < dis[i.first]){
                    dis[i.first] = i.second + di;
                    q.push({dis[i.first], i.first});
                }
            }
        }

        int ans = -1;
        for(int i = 1; i <= n; ++i){
            if(i == f and i == begin) continue;
            if(dis[i] <= 1e8 and (ans = -1 or dis[ans] > dis[i])) ans = i; 
        }
        
        return {ans, dis[ans]};
    };

    int mx = 0;
    int flag = 0;
    for(int i = 1; i <= n; ++i){
        auto sk = dij(i, i);
        if(sk.first == -1) continue;
        auto k1 = dij(sk.first, i);
        if(k1.first == -1) continue;
        flag = 1;
        mx = std::max(mx, sk.second + k1.second);
    }

    if(flag == 1) std::cout << mx << '\n';
    else std::cout << -1 << '\n';

}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--)solve();
    return 0;
}