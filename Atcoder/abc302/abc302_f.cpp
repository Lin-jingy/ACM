#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 4e5 + 5;
vector<PII>a[N];
int dis[N], st[N];
int n, m;

int dij(){
    for(int i = 1; i <= n + m; ++i) dis[i] = inf;
    dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>>q;
    q.push({0, 1});
    while(!q.empty()){
        int d = q.top().first, pos = q.top().second;
        q.pop();
        if(st[pos])continue;
        st[pos] = 1;
        for(auto i:a[pos]){
            if(d + i.second < dis[i.first]){
                dis[i.first] = d + i.second;
                q.push({dis[i.first], i.first});
            }
        }
    }
    if(dis[m] > N)return 0;
    return dis[m];
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        int flag = i + m;
        int len;
        cin >> len;
        for(int j = 1, x; j <= len; ++j){
            cin >> x;
            a[x].push_back({flag, 0});
            a[flag].push_back({x, 1});
        }
    }
    cout << dij() - 1 << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
