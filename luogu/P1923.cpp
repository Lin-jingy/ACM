#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5000005];
signed main(){
    ios::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[x];
    return 0;
}