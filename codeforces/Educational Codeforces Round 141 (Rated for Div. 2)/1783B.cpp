#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    int t;cin>>t;
    for(int ii=0;ii<t;++ii){
        int n;cin>>n;
        int a[n+1][n+1]={0};
        int i=1,j=1,flag=0;
        int min=1,max=n*n;
        int pd=0,pdd=1;
        int fx=1;
        while(1){
            if(!flag)a[i][j]=min++;
            else a[i][j]=max--;
            flag=1-flag;
            if(j>=n&&pd==0){
                ++i;
                pd=1;
                fx=-fx;
            }else if(j<=1&&pdd==0){
                ++i;
                pdd=1;
                fx=-fx;
            }else{
                j+=fx;
                pd=0;
                pdd=0;
            }
            if(max<min)break;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<n;++j){
                cout<<a[i][j]<<' ';
            }
            cout<<a[i][n]<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}