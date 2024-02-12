#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool p[100005];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string a;cin>>a;
        memset(p,0,sizeof(p));
        for(int i=0;i<n/2;++i){
            if(a[i]==a[n-i-1])p[i]=0;
            else p[i]=1;
        }
        int flag=0;
        for(int i=0;i<n/2;++i)if(p[i]==1 and p[i+1]==0)++flag;
        if(flag<=1)cout<<"yes\n";
        else cout<<"no\n";
    }

    return 0;
}