#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n;
    cin >> n;
    if(n == 1)cout << 1 << '\n';
    else if(n == 2)cout << 1 << '\n';
    else cout << n - 1 << '\n';

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
