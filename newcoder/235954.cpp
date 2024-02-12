
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int a[105][105];
// int dp[105][105];
// signed main(){
//     int n,m,ans=0;
//     cin>>n>>m;
//     for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>a[i][j];
//     for(int k=0;k<10000;++k){
//         for(int i=1;i<=n;++i){
//             for(int j=1;j<=m;++j){
//                 if(a[i][j]>a[i-1][j])dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
//                 if(a[i][j]>a[i+1][j])dp[i][j]=max(dp[i][j],dp[i+1][j]+1);
//                 if(a[i][j]>a[i][j-1])dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
//                 if(a[i][j]>a[i][j+1])dp[i][j]=max(dp[i][j],dp[i][j+1]+1);
//             }
//         }
//     }
//     for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)ans=max(ans,dp[i][j]);
//     cout<<ans;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105][105],n,m;
int b[105][105];
int dfs(int x,int y){
    if(b[x][y]!=0)return b[x][y];
    b[x][y]=1;
    if(x-1>=0&&a[x][y]>a[x-1][y])b[x][y]=max(b[x][y],dfs(x-1,y)+1);
    if(x+1<n&&a[x][y]>a[x+1][y])b[x][y]=max(b[x][y],dfs(x+1,y)+1);
    if(y-1>=0&&a[x][y]>a[x][y-1])b[x][y]=max(b[x][y],dfs(x,y-1)+1);
    if(y+1<m&&a[x][y]>a[x][y+1])b[x][y]=max(b[x][y],dfs(x,y+1)+1);
    return b[x][y];
}
signed main(){
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>a[i][j];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans;
    return 0;
}