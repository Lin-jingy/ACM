#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    int t;cin>>t;
    for(int i=0;i<t;++i){
        int n;cin>>n;
        if(n==3)cout<<"NO"<<'\n';
        else{
            cout<<"YES"<<'\n';
            if(n%2==1){
                int k1=(n-2)/2;
                int k2=-(k1+1);
                int flag=1;
                for(int j=1;j<=n;++j){
                    if(flag)cout<<k1<<' ';
                    else cout<<k2<<' ';
                    flag=1-flag;
                }
                cout<<'\n';
            }else{
                int flag=1;
                for(int j=1;j<=n;++j){
                    cout<<flag<<' ';
                    flag=-flag;
                }
                cout<<'\n';
            }
        }
    }
    return 0;
}