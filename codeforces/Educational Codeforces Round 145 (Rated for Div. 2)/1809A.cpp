#include<bits/stdc++.h>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define int long long
void solve() {
    string a;
    cin>>a;
    sort(a.begin(),a.end());
    if(a[0]==a[3])cout<<"-1\n";
    else if(a[1]==a[3] or a[0]==a[2])cout<<6<<'\n';
    else cout<<4<<'\n';
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--)solve();
    return 0;
}