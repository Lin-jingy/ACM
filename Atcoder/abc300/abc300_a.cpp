#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    int k = a + b;
    int x, flag = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> x;
        if(x == k)flag = i;
    }
    cout << flag;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
