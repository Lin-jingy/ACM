#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[31][31];
signed main(){
    int n,m;
    cin>>n>>m;
    dp[n][1]=1;dp[2][1]=1;
    for(int i=2;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(j==1)dp[j][i]=dp[n][i-1]+dp[2][i-1];
            else if(j==n)dp[j][i]=dp[n-1][i-1]+dp[1][i-1];
            else dp[j][i]=dp[n-1][i-1]+dp[n+1][i-1];
        }
    }
    cout<<dp[1][m];
    return 0;
}