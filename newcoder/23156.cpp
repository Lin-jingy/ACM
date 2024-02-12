#include <bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    vector<int> a;
    for(int i = 1;i <= 8; ++i){
        a.emplace_back(i);
        cout << i << " \n"[i == 8];
    }
    while(next_permutation(a.begin(), a.end())) {
        for(int i = 0; i < 8; ++i)cout << a[i] << " \n"[i == 7];
    }   
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}