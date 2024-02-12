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

const int N = 1e5 + 5;
vector<int>v[N];
int n, d, ans;

void dfs(int p, int deep){
    if(deep > d)return;
    ++ans;
    for(auto i:v[p]){
        dfs(i, deep + 1);
    }
}

void solve(){
    cin >> n >> d;
    --n;
    while(n--){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        v[x].push_back(y);
    }
    dfs(1, 0);
    cout << ans - 1 << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
