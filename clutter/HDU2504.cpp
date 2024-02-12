#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int a, b;
    cin >> a >> b;
    for(int i = 2 ;; i++){
        int k = i * b;            
        if(__gcd(a, k) == b){
            cout << k << '\n';
            return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
