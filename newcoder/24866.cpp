#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,q;
    cin>>n>>q;
    int a[n]={0},b[q]={0};
    for(int i=0;i<n;++i)cin>>a[i];
    b[0]=a[0]-1;
    for(int i=1;i<n;++i)b[i]=a[i]+b[i-1];
    for(int i=0;i<q;++i){
        int t;cin>>t;
        cout<<lower_bound(b,b+n,t)-b+1<<'\n';
    }
    return 0;
}