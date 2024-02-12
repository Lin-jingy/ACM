#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n;cin>>n;
    string a;
    cin>>a;
    for(int i=2;i<n;i+=2){
        if(a[i]!=a[i-2]){
            cout<<"No";
            return;
        }
    }
    for(int i=3;i<n;i+=2){
        if(a[i]!=a[i-2]){
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();

    return 0;
}