#include <bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    int n, m;
    cin >> n >> m;
    while(n--){
        string a;
        cin >> a;
        for(int i = 0; i < m - 1; ++i){
            if(a[i] == 'T' and a[i + 1] == 'T'){
                a[i] = 'P', a[i + 1] = 'C';
                i ++;
            }
        }
        cout << a << '\n';
    }
    
    
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}