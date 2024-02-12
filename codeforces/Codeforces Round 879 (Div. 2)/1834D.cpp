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
    int n, m;
    cin >> n >> m;
    vector<int>l(n), r(n), len(n);
    for(size_t i(0); i < n; ++i) cin >> l[i] >> r[i], len[i] = r[i] - l[i] + 1;
    int ans(*max_element(len.begin(), len.end()) - *min_element(len.begin(), len.end()));
    int mxl = *max_element(l.begin(), l.end());
    int mnr = *min_element(r.begin(), r.end());
    for(size_t i(0); i < n; ++i){
        ans = max(ans, min(len[i], max(mxl - l[i], r[i] - mnr)));
    }
    cout << ans * 2 << '\n';


}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
