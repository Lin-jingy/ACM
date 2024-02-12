#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n/2;++i)ans+=a[(n-1)-i]-a[i];
    cout<<ans;
    return 0;
}