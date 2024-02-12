#include<bits/stdc++.h>
using namespace std;
#define int long long
int ti[1005],va[1005],dp[1005];
signed main(){
    int t,m;cin>>t>>m;
    for(int i=1;i<=m;++i)cin>>ti[i]>>va[i];
    for(int i=1;i<=m;++i)for(int j=t;j>=ti[i];--j)dp[j]=max(dp[j-ti[i]]+va[i],dp[j]);
    cout<<dp[t];
    return 0;
}