#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[25][25],a[25][25];
void solve() {
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    for(int i=2;i<=n+1;++i){
        dp[0][i]=INT_MAX;
        dp[i][0]=INT_MAX;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    cout<<dp[n][n]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}