#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick ios::sync_with_stdio(0),cin.tie(0);
int change(int month,int day){
    int k=0;
    switch(month-1){
        case 11:k+=30;
        case 10:k+=31;
        case 9:k+=30;
        case 8:k+=31;
        case 7:k+=31;
        case 6:k+=30;
        case 5:k+=31;
        case 4:k+=30;
        case 3:k+=31;
        case 2:k+=28;
        case 1:k+=31;
    }
    k+=day;
    return k;
}
int dp[5005][5005];
class node{
public:
    int day,value;
    bool operator < (const node &a)const{
        return day<a.day;
    }
}a[1005];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    int x,y,z;
    int mx=0;
    for(int i=1;i<=n;++i){
        cin>>x>>y>>z;
        a[i].day=change(x,y);
        a[i].value=z;
        mx=max(mx,z);
    }
    sort(a+1,a+1+n);
    int ans=0;
    if(a[1].value<=m)ans=a[1].value;
    int k1,k2,k3;
    dp[1][a[1].value]=1;
    for(int i=2;i<=n;++i){
        if(a[i].value-m<=0){
            dp[i][a[i].value]=1;
            ans=max(ans,a[i].value);
        }
        for(int j=1;j<=i-1;++j){
            if(a[i].day-a[j].day>=k){
                for(int z=mx;z>=1;--z){
                    if(dp[j][z]==1 and z+a[i].value-m<=0){
                        dp[i][z+a[i].value]=1;
                        ans=max(ans,z+a[i].value);
                    }
                }
            }else break;
        }
    }
    cout<<ans;
}
signed main(){
    solve();
    return 0;
}