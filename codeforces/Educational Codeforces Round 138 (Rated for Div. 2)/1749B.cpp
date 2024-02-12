#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    vector<int>a,b;
    int n;cin>>n;
    int x;
    a.emplace_back(0);
    b.emplace_back(0);
    for(int i=1;i<=n;++i){
        cin>>x;
        a.emplace_back(x);
    }
    int mx=1;
    for(int i=1;i<=n;++i){
        cin>>x;
        b.emplace_back(x);
        if(b[mx]<b[i])mx=i;
    }
    int ans=0;
    for(int i=1;i<mx;++i){
        ans+=a[i];
        a[i+1]+=b[i];
    }
    for(int i=n;i>=mx;--i){
        ans+=a[i];
        a[i-1]+=b[i];
    }
    cout<<ans<<'\n';

    return;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}