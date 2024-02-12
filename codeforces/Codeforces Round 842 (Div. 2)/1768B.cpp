#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false); 
    int t;cin>>t;
    for(int i=0;i<t;++i){
        int n,k;cin>>n>>k;
        int a[n];
        int kk=1;
        for(int i=0;i<n;++i){
            cin>>a[i];
            if(a[i]==kk)++kk;
        }
        --kk;
        if((n-kk)%k==0)cout<<(n-kk)/k<<'\n';
        else cout<<(n-kk)/k+1<<'\n';
    }
    return 0;
}