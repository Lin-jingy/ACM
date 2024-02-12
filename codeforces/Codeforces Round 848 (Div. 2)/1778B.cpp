#include<bits/stdc++.h>
using namespace std;
#define int long long
struct ff{
    int dig;
    int k;
} p[100005];
bool fact(ff a,ff b){
    return a.dig<b.dig;
}
int a[100005];
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m,d;
        cin>>n>>m>>d;
        for(int i=1;i<=n;++i){cin>>p[i].dig;p[i].k=i;}
        for(int i=0;i<m;++i)cin>>a[i];
        sort(p+1,p+n+1,fact);
        int ans=100000;
        for(int i=0;i<m-1;++i){
            int x=p[a[i]].k;
            int y=p[a[i+1]].k;
            if(x<y)ans=min(ans,y-x);
            else ans=0;
            if(y<=x+d and d<n-1)ans=min(ans,x+d-y+1);
            else if(y>x+d)ans=0;
        }
        cout<<ans<<'\n';
    }
    return 0;
}