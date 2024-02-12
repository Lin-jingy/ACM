#include<bits/stdc++.h>
using namespace std;
#define int long long
struct carpet{
    int a;
    int b;
    int g;
    int k;
}a[100005];
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i].a>>a[i].b>>a[i].g>>a[i].k;
    int x,y;
    cin>>x>>y;
    int ans=0;
    for(int i=0;i<n;++i){
        if(a[i].a+a[i].g>=x && a[i].b+a[i].k>=y && a[i].a<=x && a[i].b<=y)ans=i+1;
    }
    cout<<ans;
    return 0;
}