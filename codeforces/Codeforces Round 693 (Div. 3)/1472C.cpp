#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 2e5 + 5;
int dp[N];

void solve(){
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; ++ i)dp[i] = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> x;
        dp[i] += x;
        if(i + x <= n)dp[i + x] = max(dp[i + x], dp[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i)ans = max(ans, dp[i]);
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
