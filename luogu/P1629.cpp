#include<bits/stdc++.h>

#define int long long 
using PII = std::pair<int,int>;
int n, m;
const int N = 1005;
std::vector<PII>v[N], vx[N];
int dis[N], dis1[N];
bool st[N], st1[N];
int ans;

void dij(){
    for(int i = 0; i < N; ++i)dis[i] = INT_MAX;
    std::priority_queue<PII, std::vector<PII>, std::greater<PII> >q;
    dis[1] = 0;
    q.push({0, 1});
    while(!q.empty()){
        int pos = q.top().second, ds = q.top().first;
        q.pop();
        if(st[pos]) continue;
        st[pos] = 1;
        for(auto i : v[pos]){
            if(i.second + ds < dis[i.first]){
                dis[i.first] = i.second + ds;
                q.push({dis[i.first], i.first});
            }
        }
    }
    for(int i = 1; i <= n; ++i)ans += dis[i];
}

void rdij(){
    for(int i = 0; i < N; ++i)dis1[i] = INT_MAX;
    std::priority_queue<PII, std::vector<PII>, std::greater<PII> >q;
    dis1[1] = 0;
    q.push({0, 1});
    while(!q.empty()){
        int pos = q.top().second, ds = q.top().first;
        q.pop();
        if(st1[pos]) continue;
        st1[pos] = 1;
        for(auto i : vx[pos]){
            if(i.second + ds < dis1[i.first]){
                dis1[i.first] = i.second + ds;
                q.push({dis1[i.first], i.first});
            }
        }
    }
    for(int i = 1; i <= n; ++i)ans += dis1[i];
}

void solve(){
    std::cin >> n >> m;
    int a, b, c;
    while(m--){
        std::cin >> a >> b >> c;
        v[a].push_back({b, c});
        vx[b].push_back({a, c});
    }
    dij();
    rdij();
    std::cout << ans;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}