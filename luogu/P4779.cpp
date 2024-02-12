#include<bits/stdc++.h>
#include<unordered_map>

#define int long long 
using PII = std::pair<int, int>;
const int N = 1e5 + 5;
std::vector<PII>v[N];
int dis[N];
bool st[N];
int n, m, s;

void dijkstra(){
    for(int i = 0; i < N; ++i)dis[i] = INT_MAX;
    dis[s] = 0;
    std::priority_queue<PII,std::vector<PII>,std::greater<PII>>q;
    q.push({0,s});
    while(!q.empty()){
        auto it = q.top();
        q.pop();
        int ds = it.first, pos = it.second;
        if(st[pos])continue;
        st[pos] = true;
        for(auto i : v[pos]){
            int p = i.first;
            int k = i.second;
            if(ds + k < dis[p]){
                dis[p] = ds + k;
                q.push({dis[p], p});
            }
        }
    }
    for(int i = 1; i <= n; ++i) std::cout << dis[i] << " \n"[i == n];
}

void solve(){
    std::cin >> n >> m >> s;
    while(m--){
        int a, b, c;
        std::cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    dijkstra();
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}