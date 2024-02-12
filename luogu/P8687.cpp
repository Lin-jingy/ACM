#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick ios::sync_with_stdio(false),cin.tie(nullptr);
int dp[1<<20];
int st[105];
void solve(){
    memset(dp,-1,sizeof dp);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        int status=0;
        for(int j=0;j<k;++j){
            int x;cin>>x;
            status|=(1<<(x-1));
        }
        st[i]=status;
        dp[status]=1;
    }
    int len=(1<<m)-1;
    for(int i=0;i<=len;++i){
        if(dp[i]!=-1){
            for(int j=0;j<n;++j){
                int kk=i|st[j];
                if(dp[kk]==-1 or dp[kk]>dp[i]+1)dp[kk]=dp[i]+1;
            }
        }
    }
    cout<<dp[len];
    return;
}
signed main(){
    quick;
    int t=1;
    while(t--)solve();
    return 0;
}