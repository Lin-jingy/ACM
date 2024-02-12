#include<bits/stdc++.h>
using namespace std;
#define int long long
const int m=1e9+7;
int a[100005];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    a[1]=1;
    for(int i=2;i<=100000;++i){
        a[i]=a[i-1]*i%m;
    }
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==1){cout<<"0\n";continue;}
        cout<<((a[n]*n)%m)*(n-1)%m<<'\n';
    }
    return 0;
}