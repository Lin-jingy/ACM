// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main(){
//     int n,m;cin>>n>>m;
//     double ans=0;
//     if(m>n){
//         int k=(m-n)/n;
//         for(int i=0;i<m%n;++i){
//             ans+=(1.0+k)/m;
//             m-=k+1;
//         }
//         n-=m%n;
//         while(n--){
//             ans+=1.0/m;
//             --m;
//         }
//     }else{
//         int k=m;
//         for(int i=0;i<m;++i){
//             ans+=1.0/k;
//             k--;
//         }
//     }
//     cout<<ans;
//     return 0;
// }
