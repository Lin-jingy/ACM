#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,q;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    cin>>q;
    for(int i=0;i<q;++i){
        int x,y,left=0,right=n-1,px=0,py=0;
        cin>>x>>y;
        px=lower_bound(a,a+n,x)-a;
        py=upper_bound(a,a+n,y)-a;
        cout<<py-px<<'\n';
    }
    return 0;
}