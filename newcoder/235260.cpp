#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1005],b[1005],c[1005],d[1005],ans;
unordered_map<int,int>p;
signed main(){
    int n,x;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)p[c[i]+d[j]]++;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            x=-(a[i]+b[j]);
            if(p.count(x))ans+=p[x];
        }
    }
    cout<<ans;
    return 0;
}