#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    int t;cin>>t;
    for(int ii=0;ii<t;++ii){
        int n;cin>>n;
        int a[n]={0};
        cin>>a[0];
        int flag=0;
        for(int i=1;i<n;++i){
            cin>>a[i];
            if(a[i]!=a[i-1])flag=1;
        }
        if(flag==1){
            sort(a,a+n);
            int min=0;
            int b[n]={0};
            int max=n-1;
            for(int j=0;j<n;j+=2)b[j]=a[min++];
            for(int j=1;j<n;j+=2)b[j]=a[max--];
            cout<<"YES"<<'\n';
            for(int j=0;j<n-1;++j)cout<<b[j]<<' ';
            cout<<b[n-1]<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}