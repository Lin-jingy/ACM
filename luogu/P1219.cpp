#include<bits/stdc++.h>
#define ing long long
using namespace std;
int a[100];
int b[15];
int c[30];
int d[30];
int n;
int flag=1;
int sum;
int fact(int k){
    if(k==n+1){
        sum++;
        if(flag<=3){
            flag++;
            for(int i=1;i<=n;++i)cout<<a[i]<<' ';
            cout<<'\n';
        }
    }
    for(int j=1;j<=n;++j){
        if(b[j]==0 && c[j+k-1]==0 && d[7-j+k-1]==0){
            a[k]=j;
            b[j]=1;c[j+k-1]=1;d[7-j+k-1]=1;
            fact(k+1);
            b[j]=0;c[j+k-1]=0;d[7-j+k-1]=0;
        }
    }
    return 0;
}
signed main(){
    cin>>n;
    fact(1);
    cout<<sum;
    return 0;
}