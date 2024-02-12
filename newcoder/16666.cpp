#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[30005];
signed main(){
    int n,m;cin>>n>>m;
    int v,p;
    for(int i=1;i<=m;++i){
        cin>>v>>p;
        for(int j=n;j>=v;--j)dp[j]=max(dp[j],dp[j-v]+p*v);
    }
    cout<<dp[n];
    return 0;
}