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
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    if((p == q and x != y) or (p == 0 and x != 0)) {
        cout << -1 << '\n';
        return ;
    }
    if(p == q  or p == 0){
        cout << 0 << '\n';
        return ;
    }
	int ans = ((x - 1) / p + 1) * q;
    x = y - x;
    p = q - p;
    ans = max(ans, ((x - 1) / p + 1) * q) ;
    cout << ans - y << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
