#include<bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    vector<int>a;
    int n,k;
    cin>>n>>k;
    int pos=n;
    --n;
    int x;
    for(int i=1;i<=k;++i){
        cin>>x;
        a.emplace_back(x);
    }
    sort(a.begin(),a.end(),greater<>());
    int ans=0;
    for(auto i:a){
        if(pos-i<=n){
            ++ans;
            n-=pos-i;
        }else break;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)solve();
}