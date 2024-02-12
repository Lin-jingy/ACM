// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define int long long
using PII = pair<int, int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    vector<bool>p(n);
    for(size_t i(0); i < n; ++i) cin >> a[i], p[i] = a[i] % 2;
    sort(ALL(a));
    for(size_t i(0); i < n; ++i) {
        if(p[i] != a[i] % 2){
            no;
            return;
        }
    }
    yes;
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
