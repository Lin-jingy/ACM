#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"


void solve(){
    int n, m, x, a = 0, b = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)cin >> x, a += x;
    for(int i = 1; i <= m; ++i)cin >> x, b += x;
    if(a > b) cout << "Tsondu\n";
    else if(a == b) cout << "Draw\n";
    else cout << "Tenzing\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
