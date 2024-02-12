#include<bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    int n;
    cin >> n;
    int x = 0, mid;
    cin >> x;
    for(int i = 1; i < n; ++ i){cin >> mid; x ^= mid;}
    if(x == 0)cout << "No\n";
    else cout << "Yes\n";

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin >> t;
    while(t--)solve();
    return 0;
}