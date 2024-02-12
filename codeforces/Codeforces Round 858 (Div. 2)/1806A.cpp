#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b>d)cout<<"-1\n";
    else if(b==d and a>=c)cout<<a-c<<'\n';
    else if (a>c)cout<<2*(d-b)+a-c<<'\n';
    else if(a<=c and c-a<=d-b)cout<<c-a+2*(d-b-(c-a))<<'\n';
    else cout<<"-1\n";
    return;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}