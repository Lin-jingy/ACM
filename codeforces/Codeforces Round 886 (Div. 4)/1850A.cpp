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
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int a[3];
    for(size_t i(0); i < 3; ++i) cin >> a[i];
    sort(a, a + 3);
    if(a[1] + a[2] >= 10)yes;
    else no;
    
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
