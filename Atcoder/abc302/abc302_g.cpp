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

const int N = 2e5 + 5;
vector<int>a, b;
map<int, map<int, int>> mp;

void solve(){
    int n;
    cin >> n;
    for(int i = 0, x; i < n; ++i) cin >> x, a.emplace_back(x), b.emplace_back(x);
    sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i) if(a[i] != b[i])mp[a[i]][b[i]]++;
    int ans = 0;
    for(int i = 1; i <= 4; ++i){
        for(int j = 1; j <= 4; ++j){
            int k = min(mp[i][j], mp[j][i]);
            ans += k; mp[i][j] -= k, mp[j][i] -= k;
        }
    }

    for(int i = 1; i <= 4; ++i){
        for(int j = 1; j <= 4; ++j){
            for(int k = 1; k <= 4; ++k){
                int mn = min({mp[i][j], mp[j][k], mp[k][i]});
                ans += 2 * mn, mp[i][j] -= mn, mp[j][k] -= mn, mp[k][i] -= mn;
            }
        }
    }
    for(int i = 1; i <= 4; ++i) ans += mp[1][i] * 3;
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
