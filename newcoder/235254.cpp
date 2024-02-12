#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int n,k;
bool check(int t){
    int time=0;
    for(int i=0;i<n;++i){
        int dt=a[i]-t;
        if(dt>0){
            if(k==1)return 0;
            if(dt%(k-1)==0)time+=dt/(k-1);
            else time+=dt/(k-1)+1;
        }
    }
    return time<=t;
}
signed main(){
    cin>>n;
    for(int i=0;i<n;++i){cin>>a[i];}
    cin>>k;
    int l=0,r=1e9;
    while(r>l+1){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    cout<<r;
    return 0;
}