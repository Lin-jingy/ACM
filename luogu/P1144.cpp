#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int N = 1e6 + 5;
const int mod = 100003;
typedef pair<int, int> PII;
int n, e;
vector<int>a[N];
int dis[N];
bool st[N];
int sum[N];

void dijkstra(){
    for(int i = 0; i < N; ++i) dis[i] = INT_MAX;
    dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    sum[1] = 1;
    while(!q.empty()){
        auto t = q.top();
        int pos = t.second, ds = t.first;
        q.pop();
        if(st[pos])continue;
        st[pos] = true;
        for(auto i : a[pos]){
            if(dis[i] > 1 + ds){
                dis[i] = 1 + ds;
                sum[i] = sum[pos];
                q.push({dis[i],i});
            }else if(dis[i] == 1 + ds)sum[i] += sum[pos];
        }
    }
    for(int i = 1; i <= n; ++i){
        if(dis[i] == INT_MAX) cout << "0\n";
        else cout << sum[n] << '\n';
    }
}

void solve(){
    cin >> n >> e;
    while(e--){
        int x, y;
        cin >> x >> y;
        if(x != y)a[x].push_back(y);
    }
    dijkstra();

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}