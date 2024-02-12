#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1005];
signed main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;++i){//构造最优
        if(i%3==1)a[i]=1;
        else a[i]=0;
    }
    int ka=0;
    for(int i=1;i<=n;++i){//统计判断
        if(a[i]==1)ka++;
    }
    if(m<=ka)cout<<"0\n";
    else{
        m-=ka;
        for(int i=n;i>=1;--i){//模拟构造
            if(a[i]==0){
                a[i]=1;
                m--;
            }
            if(m==0)break;
        }
        int ans=0;
        for(int i=n-2;i>=1;--i){//计数
            if(a[i]+a[i+1]+a[i+2]>=2)ans++;
            else break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}