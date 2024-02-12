#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    string a;cin>>a;
    int n=a.size();
    if(a[0]=='0' or a[n-1]=='1'){
        cout<<1<<'\n';
        return;
    }
    int l=0,r=n-1;
    for(int i=1;i<n;++i){
        if(a[i]=='0'){
            r=i;break;
        }
    }
    for(int i=n-1;i>=1;--i){
        if(a[i]=='1'){
            l=i;break;
        }
    }
    cout<<max(1ll,r-l+1)<<'\n';
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}