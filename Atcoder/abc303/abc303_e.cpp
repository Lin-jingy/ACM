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

const int N = 2e5 + 5;
//const int N = 5;
vector<int>v[N];
int vis[N];
vector<int>ans;

void dfs(int x, int op){
    if(vis[x])return;
    vis[x] = 1;
    if(op == 2) ans.push_back(x);
    ++op;
    if(op == 4) op = 1;
    for(auto i:v[x]){
        dfs(i, op);
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i){
        if(v[i].size() == 1){
            dfs(i, 1);
            vector<int>s;
            for(auto j:ans) s.push_back(v[j].size());
            sort(s.begin(), s.end());
            for(auto j:s)cout << j << ' ';
            return ;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
