#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[12][12], ans;
int n, m;
unordered_map<int, int>mp;

void dfs(int x, int y){
    if(x == n and y == m)++ans;
    if(x + 1 <= n and !mp.count(a[x+1][y])){
        mp[a[x+1][y]] ++;
        dfs(x + 1, y);
        mp.erase(a[x+1][y]);
    }
    if(y + 1 <= m and !mp.count(a[x][y+1])){
        mp[a[x][y+1]] ++;
        dfs(x, y + 1);
        mp.erase(a[x][y+1]);
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)for(int j = 1; j <= m; ++ j)cin >> a[i][j];
    mp[a[1][1]] = 1;
    dfs(1, 1);
    cout << ans;
}

signed main(){
    std::ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}