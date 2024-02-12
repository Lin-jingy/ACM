#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
    vector<int>v;
    int n;cin>>n;
    while(n){
        v.emplace_back(n%9);
        n/=9;
    }
    reverse(v.begin(),v.end());
    for(auto i:v){
        if(i>=4)cout<<i+1;
        else cout<<i;
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}