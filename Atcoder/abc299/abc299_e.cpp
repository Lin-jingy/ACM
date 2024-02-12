#include<bits/stdc++.h>

using namespace std;
#define int long long 
using PII = pair<int, int>;
const int N = 2e3 + 5;
vector<int>v[N];
vector<PII>op;
int p[N], st[N];
int dis[N][N];
int n, m;

bool dijkstra(int origin,int k){
    dis[origin][0] = 1;
    for(int i = 1; i <= n; ++ i)dis[origin][i] = INT_MAX, st[i] = 0;
    dis[origin][origin] = 0;
    priority_queue<PII, vector<PII>, greater<PII>>q;
    q.push({0, origin});
    while(!q.empty()){
        int di = q.top().first, pos = q.top().second;
        q.pop();
        if(st[pos])continue;
        st[pos] = 1;
        for(auto i : v[pos]){
            if(dis[origin][i] > di + 1){
                dis[origin][i] = di + 1;
                q.push({dis[origin][i], i});
            }
        }
    }
    bool flag = false;
    for(int i = 1; i <= n; ++ i){
        if(dis[origin][i] == k and !p[i])flag = true;
        if(dis[origin][i] < k)p[i] = 1;
    }
    return flag;
}

void solve(){
    cin >> n >> m;
    int x, y;
    while(m--){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int k;
    cin >> k;
    int rrk = k;
    int pos, diss;
    int f = k;
    while(k--){
        cin >> pos >> diss;
        f -= dijkstra(pos, diss);
        op.push_back({pos, diss});
    }
    if(f == 0){
        int flag = 0;
        for(auto i : op){
            int rk = 0;
            for(int j = 1; j <= n; ++ j)if(dis[i.first][j] == i.second and !p[j])rk = 1;
            flag += rk;
        }
        if(flag != rrk){
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        for(int i = 1; i <= n; ++ i)cout << 1 - p[i];
        cout << '\n';
    }else cout << "No\n";
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    solve();
    return 0;
}