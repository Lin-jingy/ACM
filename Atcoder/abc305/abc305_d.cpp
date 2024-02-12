//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int>v(n);
    for(int i = 1; i < n; ++i){
        if(i % 2 == 0) v[i] = v[i - 1] + a[i] - a[i - 1];
        else v[i] = v[i - 1];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        auto be = lower_bound(a.begin(), a.end(), l) - a.begin();
        if(be % 2 == 0) ans += a[be] - l;
        auto en = lower_bound(a.begin(), a.end(), r) - a.begin();
        if(en % 2 == 0) ans -= a[en] - r;
        if(en > be)ans += v[en] - v[be];
        cout << ans << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
