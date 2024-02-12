#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;
    while(t--){
        vector<int>a,b;
        int n,c;
        cin>>n>>c;
        int x;
        for(int i=0;i<n;++i){cin>>x;a.emplace_back(x);}
        for(int i=0;i<n;++i)b.emplace_back(a[i]+i+1);
        sort(b.begin(),b.end());
        int ans=0;
        for(int i=0;i<n&&c>=0;++i){
            if(c>=b[i])++ans,c-=b[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}