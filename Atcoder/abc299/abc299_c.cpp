#include<bits/stdc++.h>

#define int long long 
using namespace std;

void solve(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    int mx = 0;
    int k = 0;
    for(int i = 0; i < n; ++ i){
        if(a[i] == 'o')++ k;
        mx = max(mx, k);
        if(a[i] != 'o')k = 0;
    }
    mx = max(mx ,k);
    if(mx == 0 or mx == n)cout << "-1";
    else cout << mx;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    solve();
    return 0;
}