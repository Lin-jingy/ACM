#include<bits/stdc++.h>
using namespace std;
#define int long long
int L,n,m,ans;
int a[50005];
bool cheak(int x){
    int w=0,pos=0;
    for(int i=1;i<=n;i++)
        if(a[i]-pos<x)w++;
        else pos=a[i];
    return w<=m;
}
signed main(){
    cin>>L>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];a[n+1]=L;
    for(int l=1,r=L;l<=r;){
        int mid=0;
        if(cheak(mid=(l+r)/2))
            ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
}