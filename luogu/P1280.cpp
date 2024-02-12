//反向dp

#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[10005];
int p[10005];
struct node{
    int begin;
    int duration;
}a[10005];
bool cmp(node a,node b){
    return a.begin>b.begin;
}
void solve(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=k;++i){
        cin>>a[i].begin>>a[i].duration;
        p[a[i].begin]++;
    }
    sort(a+1,a+k+1,cmp);
    int flag=1;
    for(int i=n;i>=1;--i){
        if(p[i]==0)dp[i]=dp[i+1]+1;
        else {
            while(p[i]--){
                dp[i]=max(dp[i],dp[i+a[flag].duration]);
                ++flag;
            }
        }
    }
    cout<<dp[1]<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t=1;
    while(t--)solve();
    return 0;
}