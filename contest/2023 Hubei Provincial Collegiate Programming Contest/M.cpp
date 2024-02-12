#include<bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++){
        int now=m-1000*i;
        if(now%2500==0){
            cout<<n-i-now/2500<<' '<<i<<' '<<now/2500;
            return ;
        }
    }
    cout<<-1;
    return ;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}