#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main(){
    quick;
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int x,y;
        for(int i=0;i<m;++i)cin>>x>>y;
        if(n>m)cout<<"YES\n";
        else cout<<"NO\n";

    }

    return 0;
}