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
    string s;
    int n;
    cin >> s >> n;
    int ans = 0;
    for(int i = 0; i < (int)s.size(); ++i){
        if(s[i] == '1') ans += 1ll << ((int)s.size() - i - 1);
    }
    if(ans > n){
        cout << -1 << '\n';
        return;
    }
    for(int i = 0; i < (int)s.size(); ++i){
        if(s[i] == '?' and ans + (1ll << ((int)s.size() - i - 1)) <= n) ans += 1ll << ((int)s.size() - i - 1);
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
