#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;cin>>n;
    int x=sqrt(n);
    if(x*x<n)x+=1;
    if((x-1)*(x-1)>=n)x-=1;
    cout<<x-1<<'\n';
}
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;cin >> t;
    while (t--) solve();
    return 0;
}