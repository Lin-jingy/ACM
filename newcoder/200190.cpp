// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main(){
//     int n,m,k;cin>>n>>m>>k;
//     int a[n][m]={0};
//     for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>a[i][j];
//     int ans=0;
//     if(k>=min(n,m)){
//         k=max(n,m);
//     }
//     while(k--){
//         int max1[n+m]={0};
//         for(int i=0;i<n;++i)for(int j=0;j<m;++j)max1[i]+=a[i][j];
//         for(int i=0;i<m;++i)for(int j=0;j<n;++j)max1[i+n]+=a[j][i];
//         int mx=0,flag=0;
//         for(int i=0;i<n+m;++i)if(max1[i]>=mx){
//             mx=max1[i];
//             flag=i;
//         }
//         if(flag<n)for(int i=0;i<m;++i){ans+=a[flag][i];a[flag][i]=0;}
//         else for(int i=0;i<n;++i){ans+=a[i][flag-n];a[i][flag-n]=0;}
//     }
//     cout<<ans;
//     return 0;
// }
//不能用贪心！！！

