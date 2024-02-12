#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e5 + 5;
int a[N], b[N], dp[N][2];

void solve(){
    int n;
    cin >> n;
    int mx0 = 0, mx1 = 0;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    for(int i = 1; i <= n; ++ i)cin >> b[i];
    for(int i = 1; i <= n; ++ i){
        dp[i][1] = mx0 + b[i];
        dp[i][0] = mx1 + a[i];
        mx0 = max(mx0, dp[i][0]);
        mx1 = max(mx1, dp[i][1]);
    }
    cout << max(dp[n][0], dp[n][1]);

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
