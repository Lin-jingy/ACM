#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int, int>;
const int N = 2e5 + 5;
int a[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    int k1 = 0, k2 = 0, k3 = 0;
    for(int i = 1; i <= n; ++ i){
        if(a[i] == 1)k1 = i;
        if(a[i] == 2)k2 = i;
        if(a[i] == n)k3 = i;
    }
    if(abs(k1 - k2) == 1){
        if(k1 > k2)swap(k1, k2);
        if(k3 < k1)cout << k3 << ' ' << k1 << '\n';
        else cout << k2 << ' ' << k3 << '\n';
    }else{
        if(k2 > k1)cout << k1 + 1 << ' ' << k3 << '\n';
        else cout << k1 - 1 << ' ' << k3 << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
