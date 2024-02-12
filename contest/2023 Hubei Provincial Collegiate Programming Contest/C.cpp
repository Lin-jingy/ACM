#include<bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    int n, m;
    cin >> n >> m;
    if(n > m)swap(n ,m);
    if(n == 1 and m == 1)cout << 1;
    else if(n == 1 and m == 2)cout << 2;
    else if(n == 1)cout << n * m / 2 + 1;
    else cout << n + (m - n + 1) / 2;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}