#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105],kl[105],kr[105],ans;
signed main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)for(int j=0;j<i;++j)if(a[i]>a[j])kl[i]=max(kl[i],kl[j]+1);
    for(int i=n-1;i>=0;--i)for(int j=n-1;j>i;--j)if(a[i]>a[j])kr[i]=max(kr[i],kr[j]+1);
    for(int i=0;i<n;++i)ans=max(ans,kl[i]+kr[i]);
    cout<<n-ans-1;
    return 0;
}