//N皇后
#include<bits/stdc++.h>
using namespace std;
#define int long long
bool a[12],c[25],d[25];
int n,ans=0;
void dfs(int line){
    if(line==n+1){++ans;return;}
    for(int i=1;i<=n;++i){
        if(!a[i]and!c[line+i-1]and!d[line+n-i]){
            a[i]=true;
            c[line+i-1]=true;
            d[line+n-i]=true;
            dfs(line+1);
            a[i]=false;
            c[line+i-1]=false;
            d[line+n-i]=false;
        }
    }
}
signed main(){
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}