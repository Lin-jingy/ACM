#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
int a[10000];



void solve(){
    int n;
    cin >> n;
    cin >> a[1];
    int mx = a[1];
    int mn = a[1];
    for(int i = 2; i <= n; ++ i){
        cin >> a[i];
        mx |= a[i];
        mn &= a[i];
    }
    cout << mx - mn << '\n';
    
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
