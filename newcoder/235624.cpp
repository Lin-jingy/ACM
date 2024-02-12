#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[5005][5005];
string a,b;
signed main(){
    while(cin>>a>>b){
        int lena=a.size(),lenb=b.size();
        for(int i=0;i<lena;++i){
            for(int j=0;j<lenb;++j){
                if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        cout<<dp[lena][lenb]<<'\n';
    }
    return 0;
}