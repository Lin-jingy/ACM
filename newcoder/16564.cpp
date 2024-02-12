#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];//存每天最多借的教室数量
int d[1000005];//存教室数差分
struct ding{
    int begins,ends;//开始天数，结束天数
    int ding;//借教室数量
}t[1000005];
bool check(int k){
    memset(d,0,sizeof(d));
    int sum=0;
    for(int i=1;i<=k;i++){
        d[t[i].begins]+=t[i].ding;
        d[t[i].ends+1]-=t[i].ding;
    }
    for(int i=1;i<=n;i++){
        sum+=d[i];//求前缀和，若某天教室不足，则返回false
        if(sum>a[i])  return false;
    }
    return true;//若全部满足，第mid个订单则满足
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)
    cin>>t[i].ding>>t[i].begins>>t[i].ends;
    int l=1 ,r=m;//二分答案，
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    if(l==m+1)    cout<<"0"<<endl;//注意输出边界，最好自己举例子验证
    else cout<<"-1"<<endl<<l<<endl;
}