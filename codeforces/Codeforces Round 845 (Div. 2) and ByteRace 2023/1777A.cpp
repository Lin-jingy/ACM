#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        vector<int>v;
        int n;cin>>n;
        int x;
        for(int i=0;i<n;++i)cin>>x,v.emplace_back(x%2);
        int ans=0;
        auto it=v.begin();
        for(;it!=v.end()-1;++it){
            if(*it+*(it+1)==1);
            else ++ans;
        }
        cout<<ans<<'\n';
    }

    return 0;
}