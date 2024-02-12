#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main(){
    quick;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string x,a,b;
        int maxs=0,flag=0;
        for(int i=0;i<(n-1)*2;++i){
            cin>>x;
            if(x.size()==n-1&&!flag)a=x,flag=1;
            else if(x.size()==n-1&&flag)b=x;
        }
        string xa(a);
        string xb(b);
        xa.erase(0,1);
        xb.erase(n-2);
        if(xa!=xb)swap(a,b);
        a+=b[n-2];
        for(int i=0;i<n/2;++i){
            if(a[i]!=a[n-i-1]){cout<<"NO\n";goto A;}
        }
        cout<<"YES\n";
        A:;
    }

    return 0;
}