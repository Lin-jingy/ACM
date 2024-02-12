#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105],dp[105][10005];
signed main(){
    int n,m;cin>>n>>m;
    memset(dp,-10000,sizeof(dp));
    for(int i=1;i<=n;++i)cin>>a[i];
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=10005;++j){
            dp[i][j]=max(dp[i-1][j],max(dp[i-1][abs(j-a[i])]+a[i],dp[i-1][j+a[i]]+a[i]));
        }
    }
    int ans=0;
    for(int i=0;i<=m;++i)ans=max(ans,dp[n][i]);
    cout<<ans;
    return 0;
}