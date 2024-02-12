#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,w,v,dp[105];
signed main(){
    int n,t;cin>>n>>t;
    for(int i=0;i<n;++i){
        cin>>x>>w>>v;
        while(x--){
            for(int j=t;j>=w;--j){
                dp[j]=max(dp[j],dp[j-w]+v);
            }
        }
    }
    cout<<dp[t];
    return 0;
}