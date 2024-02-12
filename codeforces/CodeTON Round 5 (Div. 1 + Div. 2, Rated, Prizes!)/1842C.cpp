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
int a[N], dp[N][2], p[N]; //dp[i][0]为不消除  dp[i][1]为消除

void solve(){
    int n;
    cin >> n;
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], dp[i][0] = dp[i][1] = p[i] = 0;
    for(int i = 1; i <= n; ++i){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if(p[a[i]] != 0) dp[i][1] = max(dp[p[a[i]]][0] + i - p[a[i]] + 1, dp[p[a[i]]][1] + i - p[a[i]]);
        else dp[i][1] = dp[i][0];
        p[a[i]] = i;
    }
    cout << max(dp[n][1], dp[n][0]) << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
