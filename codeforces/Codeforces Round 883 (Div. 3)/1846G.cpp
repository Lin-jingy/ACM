#include<bits/stdc++.h>

using i64 = long long;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while(T--){

        int n, m;
        std::cin >> n >> m;
        
        std::string s;
        std::cin >> s;
        int now = std::stoi(s, 0, 2);

        std::vector<int> good(m + 1), bad(m + 1), day(m + 1);
        for(int i(1); i <= m; ++i) {
            std::cin >> day[i];
            std::cin >> s, good[i] = stoi(s, 0, 2);
            std::cin >> s, bad[i] = stoi(s, 0, 2);
        }

        if(now == 0){
            std::cout << 0 << '\n';
            continue;
        }

        std::vector<std::vector<std::pair<int, int>>>a(1024);
        for(int i = 0; i < 1024; ++i){
            for(int j = 1; j <= m; ++j){
                a[i].push_back({(i ^ good[j]) & i | bad[j], day[j]});
            }
        }

        std::vector<i64>dis(1024, INT_MAX);
        std::vector<bool>vis(1024);
        std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int>>,std::greater<std::pair<int, int>>>q;
        q.push({0, now});
        while(!q.empty()){
        auto it = q.top();
        q.pop();
        int ds = it.first, pos = it.second;
        if(vis[pos])continue;
        vis[pos] = true;
        for(auto i : a[pos]){
            int p = i.first;
            int k = i.second;
            if(ds + k < dis[p]){
                dis[p] = ds + k;
                q.push({dis[p], p});
            }
        }
    }     

        if(dis[0] == INT_MAX) std::cout << "-1\n";
        else std::cout << dis[0] << '\n';

    }
}
