// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// struct node{
//     int pos;
//     int last;
// };
// queue<node>q;
// signed main(){
//     int v,n;cin>>v>>n;
//     int a[n]={0},ans=v;
//     for(int i=0;i<n;++i)cin>>a[i];
//     sort(a,a+n);
//     for(int i=n-1;i>=0;--i){
//         q.push({i,v-a[i]});
//         q=queue<node>();
//         while(!q.empty()){
//             node k=q.front();
//             q.pop();
//             for(int j=k.pos;j>=0;--j){
//                 if(k.last>=a[j]){
//                     q.push({j,k.last-a[j]});
//                     ans=min(ans,k.last-a[j]);
//                 }
//             }
//         }
//     }
//     cout<<ans;
//     return 0;
// }

//AC代码
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int a[35],dp[35][20005];
// signed main(){
//     int v,n;
//     cin>>v>>n;
//     for(int i=1;i<=n;++i)cin>>a[i];
//     for(int i=1;i<=n;++i){
//         for(int j=1;j<=v;++j){
//             if(j>=a[i])dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
//             else dp[i][j]=dp[i-1][j];
//         }
//     }
//     cout<<v-dp[n][v];
//     return 0;
// }

//优化代码
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[35],dp[20005];
signed main(){
    int v,n;
    cin>>v>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        for(int j=v;j>=a[i];--j){
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    cout<<v-dp[v];
    return 0;
}