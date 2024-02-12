// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int a[100005],dp[100005],dp1[100005];
// signed main(){
//     int k=0;
//     while(cin>>a[k++]);
//     --k;
//     for(int i=0;i<k;++i)for(int j=0;j<i;++j)if(a[i]<=a[j])dp[i]=max(dp[j]+1,dp[i]);
//     int ans=0;
//     for(int i=0;i<k;++i)ans=max(ans,dp[i]);
//     cout<<ans+1<<'\n';
//     //Dilworth定理
//     for(int i=0;i<k;++i)for(int j=0;j<i;++j)if(a[i]>=a[j])dp1[i]=max(dp1[j]+1,dp1[i]);
//     int ans1=0;
//     for(int i=0;i<k;++i)ans1=max(ans1,dp1[i]);
//     cout<<ans1+1;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],dp[100005],dp1[100005],k;
signed main(){
    while(cin>>a[k++]);
    --k;
    for(int i=0;i<k;++i)for(int j=0;j<i;++j){
        if(a[i]<=a[j])dp[i]=max(dp[j]+1,dp[i]);
        if(a[i]>=a[j])dp1[i]=max(dp1[j]+1,dp1[i]);
    }
    int ans=0,ans1=0;
    for(int i=0;i<k;++i){
        ans=max(ans,dp[i]);
        ans1=max(ans1,dp1[i]);
    }
    cout<<ans+1<<'\n'<<ans1+1;
    return 0;
}