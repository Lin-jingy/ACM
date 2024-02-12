#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e5 + 5;
class node{public:int t, x, y;}a[N];
int dp[N];

void solve(){
    int n, m;
    cin >> n >> m;
    int t, x, y;
    for(int i = 1; i <= m; ++ i)cin >> t >> x >> y, a[i] = {t, x, y}, dp[i] = INT_MIN;
    for(int i = 1; i <= m; ++ i){
        if(a[i].x + a[i].y - 2 <= a[i].t)dp[i] = 1;
        for(int j = max(i - 4 * n, 1ll); j < i; ++ j){
            if(abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) <= a[i].t - a[j].t)dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; ++ i)ans = max(ans, dp[i]);
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
