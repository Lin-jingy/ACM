
//TLE
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int a[100005];
// bool fact(int a,int b){return a>b;}
// int answer;
// signed main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;++i){
//         cin>>a[i];
//     }
//     sort(a,a+n,fact);
//     int k=n-1;
//     while(k>1){
//         int sum=0;
//         sum+=a[k];
//         --k;
//         sum+=a[k];
//         answer+=sum;
//         a[k]=sum;
//         sort(a,a+k,fact);
//     }
//     cout<<a[0]+a[1]+answer;
//     return 0;
// }

#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
int answer;
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        q.push(x);
    }
    while(q.size()>=2){
        int sum=0;
        sum+=q.top();
        q.pop();
        sum+=q.top();
        q.pop();
        answer+=sum;
        q.push(sum);
    }
    cout<<answer;
    return 0;
}