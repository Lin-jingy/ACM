#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100000]={0};
signed main(){
    int l,m;
    int sum=0;
    cin>>l>>m;
    for(int i=0;i<=l;++i){
        a[i]=1;
    }
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        for(int j=u;j<=v;++j){
            a[j]=0;
        }
    }
    for(int i=0;i<=l;i++){
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}