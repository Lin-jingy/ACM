//27.7%
//wa








#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=45;
int a[N];
//三维DP
/*
 * dp[i][j][k]
 *     i表示到第i位
 *     j表示将当前位的-1改成j
 *     k表示第k位连续递减
*/
int dp[N][N][3];
int sum[N][N];
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(a[1]==-1){
        for(int j=0;j<=40;++j){
            dp[1][j][1]=1;
            sum[1][j]=j;
        }
    }
    else{
        dp[1][a[1]][1]=1;
        sum[1][a[1]]=a[1];
    }
    for(int i=2;i<=n;++i){
        if(a[i-1]==-1){//前一项不确定
            if(a[i]==-1){//这一项不确定
                for(int j=0;j<=40;++j){//枚举前一项的选择的值
                    for(int k=0;k<=40;++k){//枚举这一项选择的值
                        if(k<=sum[i-1][j]*1.0/(i-1)){
                            if(j<k)dp[i][k][2]=dp[i-1][j][1];
                            else dp[i][k][1]=dp[i-1][j][1]+dp[i-1][j][2];
                            sum[i][k]=sum[i-1][j]+k;
                        }
                    }
                }
            }else{//这一项确定
                for(int j=0;j<=40;++j){//枚举前一项的值
                    if(a[i]<=sum[i-1][j]*1.0/(i-1)){
                        if(a[i]<j)dp[i][a[i]][2]=dp[i-1][j][1];
                        else dp[i][a[i]][1]=dp[i-1][j][1]+dp[i-1][j][2];
                        sum[i][a[i]]=sum[i-1][j]+a[i];
                    }
                }
            }
        }else{//前一项确定
            if(a[i]==-1){//这一项不确定
                for(int j=0;j<=40;++j){
                    if(j<=sum[i-1][a[i-1]]*1.0/(i-1)){
                        if(j<a[i-1])dp[i][j][2]=dp[i-1][a[i-1]][1];
                        else dp[i][j][1]=dp[i-1][a[i-1]][1]+dp[i-1][a[i-1]][2];
                        sum[i][j]=sum[i-1][a[i]]+a[i];
                    }
                }
            }else{//这一项确定
                if(a[i]<=sum[i-1][a[i-1]]*1.0/(i-1)){
                    if(a[i]<a[i-1])dp[i][a[i]][2]=dp[i-1][a[i-1]][1];
                    else dp[i][a[i]][1]=dp[i-1][a[i-1]][1]+dp[i-1][a[i-1]][2];
                    sum[i][a[i]]=sum[i-1][a[i-1]]+a[i];
                }
            }
        }
    }
    int ans=0;
    for(int j=0;j<=40;++j){
        ans+=(dp[n][j][1]+dp[n][j][2])%mod;
    }
    cout<<ans%mod;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    while(t--)solve();
    return 0;
}