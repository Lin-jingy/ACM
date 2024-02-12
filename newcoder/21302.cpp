//21302
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int dp[55][3];
void solve() {
    string a;
    cin >> a;
    int n = a.size();
    a = '0' + a;
    for(int i = 1; i <= n; ++i){
        int k = (a[i] - '0') % 3;
        if(k == 0){
            dp[i][0] = dp[i-1][0] * 2 + 1;
            dp[i][1] = dp[i-1][1] * 2;
            dp[i][2] = dp[i-1][2] * 2;
        }else if(k == 1){
            dp[i][0] = dp[i-1][2] + dp[i-1][0];
            dp[i][1] = dp[i-1][0] + dp[i-1][1] + 1;
            dp[i][2] = dp[i-1][1] + dp[i-1][2];
        }else{
            dp[i][0] = dp[i-1][1] + dp[i-1][0];
            dp[i][1] = dp[i-1][2] + dp[i-1][1];
            dp[i][2] = dp[i-1][0] + dp[i-1][2] + 1;
        }
    }
    cout << dp[n][0] % mod;

}
signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    while(t--)solve();
    return 0;
}