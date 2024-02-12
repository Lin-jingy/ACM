#include<bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    int n, k;
    cin >> n >> k;
    int x = 0, mid;
    int flag = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> mid;
        if(i == k)flag = mid;
        else x ^= mid;
    }
    if(x < flag)cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin >> t;
    while(t--)solve();
    return 0;
}