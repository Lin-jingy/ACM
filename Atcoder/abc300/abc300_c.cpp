#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
string a[105];
int n, m;

int dfs(int x, int y){
    int p[4] = {0, 0, 0, 0};
    int xx = x, yy = y;
    while(xx > 1 and yy > 1 and a[xx - 1][yy - 1] == '#')--xx, --yy;
    p[0] = abs(x - xx);
    xx = x, yy = y;
    while(xx > 1 and yy < m and a[xx - 1][yy + 1] == '#')--xx, ++yy;
    p[1] = abs(x - xx);
    xx = x, yy = y;
    while(xx < n and yy > 1 and a[xx + 1][yy - 1] == '#')++xx, --yy;
    p[2] = abs(x - xx);
    xx = x, yy = y;
    while(xx < n and yy < m and a[xx + 1][yy + 1] == '#')++xx, ++yy;
    p[3] = abs(x - xx);
    int ans = INT_MAX;
    for(int i = 0; i < 4; ++ i)ans = min(ans, p[i]);
    return ans;
}

void solve(){
    cin >> n >> m;
    string x;
    for(int i = 1; i <= n; ++ i){
        cin >> x;
        a[i] += '.';
        a[i] += x;

    }
    int k = min(n, m);
    vector<int>v(k + 1);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(a[i][j] == '#')v[dfs(i, j)] ++;
        }
    }
    for(int i = 1; i <= k; ++ i)cout << v[i] << ' ';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
