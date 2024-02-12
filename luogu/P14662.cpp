#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int c[n]={0},v[n]={0};
        for(int i=0;i<n;++i){
            cin>>c[i]>>v[i];
        }
        int l=1,r=1e4,ans=0,dig=0;
        while(l<=r){
            dig=0;
            int mid=l+r>>1;
            int kk[n]={0};
            for(int i=0;i<n;++i)kk[i]=v[i]-mid*c[i];
            sort(kk,kk+n,greater<int>());
            for(int i=0;i<k;++i)dig+=kk[i];
            if(dig>=0){ans=mid;l=mid+1;}
            else r=mid-1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}