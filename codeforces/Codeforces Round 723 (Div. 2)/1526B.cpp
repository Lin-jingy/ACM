#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i <= 11 and i * 111 <= n; ++ i){
        if((n - 111 * i) % 11 == 0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
