// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define int long long
using PII = pair<int, int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 2e5 + 5;
vector<int>s[N];

void solve(){
    int n, k, x;
    cin >> n >> k;
    vector<int>a(n + 1);
    vector<bool>vis(n + 1);
    stack<int>sk;

    for(size_t i(1); i <= n; ++i) cin >> a[i], s[i].clear(), sk.push(i);
    while(k--) cin >> x, a[x] = 0;
    for(size_t i(1); i <= n; ++i){
        cin >> k;
        while(k--) cin >> x, s[i].push_back(x);
    }

    while(!sk.empty()){
        int sum(0), pri(0);
        int tp = sk.top();
        sk.pop();
        if(vis[tp]) continue;
        for(auto i:s[tp]) if(vis[i]) ++sum, pri += a[i];
        if(sum == (int)s[tp].size()){
            vis[tp] = 1;
            if(s[tp].size() != 0)a[tp] = min(a[tp], pri);
        }else{
            sk.push(tp);
            for(auto i:s[tp]) sk.push(i);
        }
    }
    for(size_t i(1); i <= n; ++i) cout << a[i] << " \n"[i == n];
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
