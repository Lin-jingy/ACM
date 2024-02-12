#include<bits/stdc++.h>
using namespace std;
int ans,n,m;
void dfs(int x,int y){
    if(x==n and y==m){++ans;return ;}
    if(x+1<=n and y+2<=m)dfs(x+1,y+2);
    if(x+1<=n and y-2>=1)dfs(x+1,y-2);
    if(x+2<=n and y+1<=m)dfs(x+2,y+1);
    if(x+2<=n and y-1>=1)dfs(x+2,y-1);
}
signed main(){
    cin>>m>>n;
    dfs(1,1);
    cout<<ans;
    return 0;
}