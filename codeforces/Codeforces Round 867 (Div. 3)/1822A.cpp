#include<bits/stdc++.h>

using namespace std;
#define int long long 
int a[55], b[55];

void solve(){
    int n, q;
    cin >> n >> q;
    int rq = q;
    int x, mx = -1;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    for(int i = 1; i <= n; ++ i)cin >> b[i];
    for(int i = 1; i <= n and q >= 0; ++ i, -- q){
        if(a[i] <= q and (mx == -1 or b[i] > b[mx]))mx = i;
    }
    cout << mx << '\n';

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>> t;
    while(t--)solve();
    return 0;
}