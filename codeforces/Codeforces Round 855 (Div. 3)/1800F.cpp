//TLE
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
// int n;
// int p[200005][26];//存储每个字母出现的数量
// auto cmp(int a,int b){
//     int k=0;
//     for(int i=0;i<26;++i){
//         int mid=p[a][i]+p[b][i];
//         if(mid>0){
//             ++k;
//             if(mid%2!=1)return false;
//         }
//     }
//     if(k==25)return true;
//     else return false;
// }
// signed main(){
//     quick;
//     cin>>n;
//     string a[n];
//     int ans=0;
//     bool flag[n]={false};//长度奇偶判断如果为True则为奇数，否则为偶数
//     for(int i=0;i<n;++i){//输入处理
//         cin>>a[i];
//         for(auto it:a[i]){
//             p[i][it-'a']++;
//         }
//         if(a[i].size()%2==1)flag[i]=1;
//         else flag[i]=0;
//     }
//     for(int i=0;i<n;++i){
//         for(int j=i+1;j<n;++j){
//             if(flag[i]+flag[j]!=1)continue;
//             ans+=cmp(i,j);
//         }
//     }
//     cout<<ans<<'\n';
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main(){
    quick;
    int n;cin>>n;
    int p[200005][26];//存储每个字母出现的数量
    string a[n];
    int ans=0;
    bool flag[n]={false};//长度奇偶判断如果为True则为奇数，否则为偶数
    for(int i=0;i<n;++i){//输入处理
        cin>>a[i];
        for(auto it:a[i]){
            p[i][it-'a']++;
        }
        if(a[i].size()%2==1)flag[i]=1;
        else flag[i]=0;
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            
        }
    }
    cout<<ans<<'\n';
    return 0;
}