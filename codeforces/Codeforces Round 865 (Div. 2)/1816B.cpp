#include<bits/stdc++.h>

using namespace std;
#define int long long 
int a[2][200005];

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int k=2*n;
        int kk=n+1;
        for(int i=1;i<n;++i){
            if(i%2==1)a[0][i]=--k;
            else a[1][i]=--k;
            if(i%2==1)a[1][i]=--kk;
            else a[0][i]=--kk;
        }
        a[1][n]=2*n;
        a[0][n]=1;
        for(int i=1;i<=n;++i)cout<<a[0][i]<<" \n"[i==n];
        for(int i=1;i<=n;++i)cout<<a[1][i]<<" \n"[i==n];
    }
    return 0;
}