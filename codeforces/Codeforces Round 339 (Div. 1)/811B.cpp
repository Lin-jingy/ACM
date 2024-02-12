#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10005];
void solve() {
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    int l,r,x;
    while(m--){
        cin>>l>>r>>x;
        if(l==r)cout<<"Yes\n";
        else{
            int k1=0,k2=0;
            for(int i=l;i<=r;++i){
                if(a[i]<a[x])++k1;
                else if(a[i]>a[x])++k2;
            }
            if(k1==x-l and k2==r-x)cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

}
signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    while(t--)solve();
    return 0;
}