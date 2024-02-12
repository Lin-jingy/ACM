#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int N = 3e4+5;
vector <int> v[N];
queue <int> q;
vector <int> topology;
int in[N];
unordered_map<int, int>mp;
unordered_map<int, int>ct[N];

void add(int x, int y){
    v[x].push_back(y);
    ct[x][y] = 1;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        add(x, y);
        in[y] ++;
        
    }
    for(int i = 1; i <= n; ++i) if(in[i] == 0) q.push(i);
    int flag = 1;
    while(!q.empty()){
        int j = q.front();
        q.pop();
        topology.push_back( j );//存储拓扑序
        mp[j] = flag ++;
        for(auto i : v[j]){
            in[i] --;
            if(in[i] == 0)q.push(i);
        }
    }
    //for(auto i : topology)cout << i << ' ';
    //cout << '\n';
    int ans = 0;
    for(auto i : topology){
        int len = v[i].size();
        for(int j = 0; j < len; ++j){
            for(int k = j + 1; k < len; ++k){
                if(mp[v[i][j]] < mp[v[i][k]] and ct[i].count(v[i][k])) ++ans, ct[i].erase(v[i][k]);
                else if(mp[v[i][j]] > mp[v[i][k]] and ct[i].count(v[i][j])) ++ans, ct[i].erase(v[i][j]);
            }
        }
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}