#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    int x;
    int k=0,k1=0;
    int mx=0;
    for(int i=1;i<=n;++i){
        cin>>x;
        if(x==0)++k;
        else ++k1;
        mx=max(mx,x);
    }
    if(k<=k1+1)cout<<0<<'\n';
    else if(mx>=2)cout<<1<<'\n';
    else if(mx==0)cout<<1<<'\n';
    else cout<<2<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}