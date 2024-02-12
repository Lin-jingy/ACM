#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
#define int long long 
const int N = 5e4+5;
vector<int>v[N];
bool p[N];
int ans = N,n;
int out[N];

void add(int x,int y){
    v[x].push_back(y);
    v[y].push_back(x);
}

int dfs(int x){
    p[x] = true;
    int res = 0;
    int sum = 1;
    int len = v[x].size();
    for(int i = 0; i < len; ++i){
        if(!p[v[x][i]]){
            int k = dfs(v[x][i]);
            sum += k;
            res = max(res, k);
        }
        
    }
    res = max(res, n - sum);
    out[x] = max(out[x], res);
    ans = min(ans, res);
    return sum;//返回目前块大小
}

void solve(){
    cin>>n;
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        add(x,y);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i) if(out[i] == ans)cout<<i<<' ';
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    solve();
    return 0;
}