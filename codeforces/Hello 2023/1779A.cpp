#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[100005],x;
int flag;
bool pd=false;
signed main(){
    ios::sync_with_stdio(false);
    int t;cin>>t;
    for(int i=0;i<t;++i){
        pd=false;
        flag=0;
        int n;cin>>n;
        cin>>a[0];
        if(a[0]=='R'){
            for(int i=1;i<n;++i){
                cin>>a[i];
                if(a[i]=='L')pd=true;
            }
            if(pd)cout<<"0"<<'\n';
            else cout<<"-1"<<'\n';
        }else{
            for(int i=1;i<n;++i){
                cin>>a[i];
                if(!flag&&a[i]=='R')flag=i;
                else if(flag&&a[i]=='L')pd=1;
            }
            if(pd==1)cout<<"0"<<'\n';
            else if(flag)cout<<flag<<'\n';
            else cout<<"-1"<<'\n';
        }
    }
    return 0;
}