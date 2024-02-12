//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 2e5 + 5;
vector<int>a[N];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for (size_t i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        a[x].emplace_back(y);
        a[y].emplace_back(x);
    }
    priority_queue<PII>q;
    for (size_t i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        q.emplace(y, x);
    }
    vector<bool>p(n + 1, false);
    while(!q.empty()){
        PII it = q.top();
        int pos = it.second, dis = it.first;
        q.pop();
        if(p[pos] or dis < 0) continue;
        p[pos] = true;
        for(auto i:a[pos]) q.emplace(dis - 1, i);
    }
    int ans = 0;
    for(auto i:p) if(i == true) ++ans;
    cout << ans << '\n';
    for(size_t i = 1; i <= n; ++i) if(p[i] == true) cout << i << ' ';

}
    

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
