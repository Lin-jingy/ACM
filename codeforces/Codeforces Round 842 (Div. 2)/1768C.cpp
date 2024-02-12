#include<bits/stdc++.h>
using namespace std;
#define int long long
bool fact(int a,int b){
    return a>b;
}
signed main(){
    ios::sync_with_stdio(false); 
    int t;cin>>t;
    for(int i=0;i<t;++t){
        int n;cin>>n;
        int a[n+1]={0};
        int ansa[n+1]={0},ansb[n+1]={0};
        bool fa[n+1]={false},fb[n+1]={false};
        for(int j=1;j<=n;++j)cin>>a[j];
        sort(a+1,a+n+1,fact);
        int ai=n,bi=n;
        int flag=0;
        for(int j=1;j<=n;++j){
            if(!fa[a[j]]){
                ansa[j]=a[j];
                fa[a[j]]=true;
                while(fb[bi])--bi;
                fb[bi]=true;
                ansb[j]=bi;
            }
            else if(!fb[a[j]]){
                ansb[j]=a[j];
                fb[a[j]]=true;
                while(fa[ai])--ai;
                fa[ai]=true;
                ansa[j]=ai;
            }else {
                cout<<"NO"<<'\n';flag=1;
                break;
                
            }
        }
        if(!flag){
                cout<<"YES"<<'\n';
                for(int j=1;j<=n;++j)cout<<ansa[j]<<' ';
                cout<<'\n';
                for(int j=1;j<=n;++j)cout<<ansb[j]<<' ';
                cout<<'\n';
            }
    }
    return 0;
}